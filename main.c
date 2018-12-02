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
	setTypeNames("Calendar0", "Calendar1", "Calendar2");
	Event * e = new_Event(0,3, 4, "Lunch", "A midday meal.");

	printf("Hello World\n");
	printf("Start Time: %d\nEnd Time: %d\n", e -> start, e-> end);
	printf("Calendar is: %s\n\n",typeNames[e -> type]);

	char str[10000];
	printf("%s\n\n", toEventString(e, str));

	Date * day = malloc(sizeof(Date));
	Event * events[24];	
	for(int i = 0; i < 24; i++)
		events[i] = NULL;
	
	day = new_date(events, 02, August, 2016);

	addEvent(day, e);
	
	printf("%s\n", toDateString(day, str));
	
    return 0;
}
