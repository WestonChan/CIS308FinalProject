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

EventType getType(char type[TITLELENGTH]) {
	if(strcmp(typeNames[0], type) == 0) return 0;
	if(strcmp(typeNames[1], type) == 0) return 1;
	if(strcmp(typeNames[2], type) == 0) return 2;
	
	return -1;
}

char * toEventString(Event * e, char * str) {
	str[0] = '\0';
	strcat(str, e -> title);
	strcat(str, "\n\n");
	strcat(str, e -> desc);

	return str;
}

int Equals(Event * e1, Event * e2) {
	if(e1->type == e2->type && e1->start == e2->start && e1->end == e2->end && 
		strcmp(e1->title, e2->title) == 0 && strcmp(e1->desc, e2->desc)) return 1;
	return 0;
}
