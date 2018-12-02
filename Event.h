//
//  Event.h
//  Week 8 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef Event_h
#define Event_h

#include <stdio.h>

#define TITLELENGTH 21
#define DESCLENGTH 201

typedef enum EventType {Calendar0, Calendar1, Calendar2} EventType;
static char typeNames[3][TITLELENGTH] = {"Calendar0","Calendar1","Calendar2",};

typedef struct Event {
	EventType type;
	int start;
	int end;
	char title[TITLELENGTH];
	char desc[DESCLENGTH];
} Event;

Event * new_Event(EventType type, int start, int end, char * title, char * desc);

EventType getType(char type[TITLELENGTH]);

void setTypeNames(char type0[TITLELENGTH], char type1[TITLELENGTH], char type2[TITLELENGTH]);

char * toEventString(Event * e, char * str);

#endif /* Event_h */
