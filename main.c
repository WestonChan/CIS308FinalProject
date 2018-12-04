//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdlib.h>
#include "Date.h"
#include "Event.h"
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
	setTypeNames("Calendar0", "Calendar1", "Calendar2");
	Event * e = new_Event(2,3,24, "Lunch", "A midday meal.");

	printf("Hello World\n");
	printf("Start Time: %d\nEnd Time: %d\n", e -> start, e -> end);
	printf("Calendar is: %s\n\n",typeNames[e -> type]);

	char str[10000];
	printf("%s\n\n", toEventString(e, str));

	Date * day = malloc(sizeof(Date));
	Event * events[3][24];	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 24; j++)
		events[i][j] = NULL;
	
	day = new_date(events, 02, August, 2016);

	addEvent(day, e);
	
	printf("%s\n", toDateString(day, str));
	
    return 0;
}

void export(LinkedList l) {
	FILE * fp = fopen("Schedule.csv", "w");
	
	




	fclose(fp);
}

LinkedList import() {
	FILE * fp = fopen("Schedule.csv", "r");
	
	




	fclose(fp);

}
