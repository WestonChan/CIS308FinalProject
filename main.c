//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdlib.h>
#include "Date.h"
#include "Event.h"

int main(int argc, const char * argv[]) {
	Date * day = malloc(sizeof(Date));
	setTypeNames("Calendar0", "Calendar1", "Calendar2");
	Event * e = new_Event(0,day,"03:30", "04:30", "Lunch", "");

	printf("Hello World\n");
	printf("Start Time: %s\nEnd Time: %s\n", e -> start, e-> end);
	printf("Calendar is: %s\n",typeNames[e -> type]);
    return 0;
}
