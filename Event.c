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



Event * new_Event(EventType type, char * start, char * end, char * title, char * desc) {
	if(start == NULL || end == NULL || title == NULL || desc == NULL) return NULL;
	if(strlen(start) >= TIMELENGTH || strlen(end) >= TIMELENGTH|| strlen(title) >= TITLELENGTH ||
		strlen(desc) >= DESCLENGTH) return NULL;

	Event * e = malloc(sizeof(Event));
	
	e -> type = type;
	strcpy(e -> start, start);
	strcpy(e -> end, end);
	strcpy(e -> title, title);
	strcpy(e -> desc, desc);
	return e;
}

EventType getType(char type[51]) {
	if(strcmp(typeNames[0], type) == 0) return 0;
	if(strcmp(typeNames[1], type) == 0) return 1;
	if(strcmp(typeNames[2], type) == 0) return 2;
	
	return -1;
}

void setTypeNames(char type0[51], char type1[51], char type2[51]) {
	strcpy(typeNames[0], type0);
	strcpy(typeNames[1], type1);
	strcpy(typeNames[2], type2);
}

char * toEventString(Event * e, char * str) {
	str[0] = '\0';
	strcat(str, e -> title);
	strcat(str, "\n\n");
	strcat(str, e -> desc);

	return str;
}
