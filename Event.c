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

Event * new_Event(char * start, char * end) {
	Event * e = malloc(sizeof(Event));
	strcpy(e -> start, start);
	strcpy(e -> end, end);
	return e;
}
