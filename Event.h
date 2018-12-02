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

#define TYPELENGTH 21
#define TITLELENGTH 21
#define TIMELENGTH 6
#define DESCLENGTH 201

typedef enum EventType {Calendar0, Calendar1, Calendar2} EventType;
static char typeNames[3][TYPELENGTH];

typedef struct Event {
	EventType type;
	char start[TIMELENGTH];
	char end[TIMELENGTH];
	char title[TITLELENGTH];
	char desc[DESCLENGTH];
} Event;

Event * new_Event(EventType type, char * start, char * end, char * title, char * desc);

EventType getType(char type[TYPELENGTH]);

void setTypeNames(char type0[TYPELENGTH], char type1[TYPELENGTH], char type2[TYPELENGTH]);

char * toEventString(Event * e, char * str);

#endif /* Event_h */
