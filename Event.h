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

typedef struct Event {
	char start[6];
	char end[6];
} Event;

Event * new_Event(char * start, char * end);

#endif /* Event_h */
