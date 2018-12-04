//
//  Event.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Event.h"

Event * new_Event(EventType type, int start, int end, char * title, char * desc) {
	if(title == NULL || desc == NULL) return NULL;
	if(start < 0 || start >= 24 || end < 0 || end > 24|| strlen(title) >= TITLELENGTH ||
		strlen(desc) >= DESCLENGTH) return NULL;

	Event * e = malloc(sizeof(Event));
	
	e -> type = type;
	e -> start = start;
	e -> end = end;
	strcpy(e -> title, title);
	strcpy(e -> desc, desc);
	return e;
}

char * toEventString(Event * e, char * str) {
	str[0] = '\0';
	strcat(str, e -> title);
	strcat(str, "\n\n");
	strcat(str, e -> desc);

	return str;
}

void setTypeNames(char type0[TITLELENGTH], char type1[TITLELENGTH], char type2[TITLELENGTH]) {
	strcpy(typeNames[0], type0);
	strcpy(typeNames[1], type1);
	strcpy(typeNames[2], type2);
}

void printTypes(){
	printf("%s\n",typeNames[0]);
	printf("%s\n",typeNames[1]);
	printf("%s\n",typeNames[2]);
}

char * returnTypes(int i) {
	return typeNames[i];
}

int Equals(Event * e1, Event * e2) {
	if(e1->type == e2->type && e1->start == e2->start && e1->end == e2->end && 
		strcmp(e1->title, e2->title) == 0 && strcmp(e1->desc, e2->desc)==0) return 1;
	return 0;
}
