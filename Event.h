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
#include "Date.h"

typedef enum EventType {Calendar0, Calendar1, Calendar2} EventType;

char typeNames[3][51];

typedef struct Event {
	EventType type;
	Date * day;
	char start[6];
	char end[6];
	char title[51];
	char desc[201];
} Event;

Event * new_Event(EventType type, Date * day, char * start, char * end, char * title, char * desc);

EventType getType(char type[51]);

void setTypeNames(char type0[51], char type1[51], char type2[51]);

char * toString();

#endif /* Event_h */
