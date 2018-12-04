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


void export(LinkedList * l) {
	FILE * fp = fopen("Schedule.rofl", "w");

	fprintf(fp,"%s^%s^%s\n", typeNames[0], typeNames[1], typeNames[2]);

	while(l != NULL) {
		fprintf(fp, "%d^%d^%d\n", l->day->day, l->day->month, l->day->year);
		for(int j = 0; j < 3; j++)
			for(int i = 0; i < 24; i++) {
				Event * e = l->day->event[j][i];
				if(e == NULL) {
					fprintf(fp, "^^^^");
				} else {
					fprintf(fp, "%d^%d^%d^%s^%s", e->type, e->start, e->end, e->title, e->desc);
				}
				fprintf(fp,"\n");
			}
		fprintf(fp,"\n");
		l = l->next;
	}
	fclose(fp);
	
}

LinkedList * import() {
	FILE * fp = fopen("Schedule.rofl", "r");
	
	




	fclose(fp);
	return NULL;
}

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

	LinkedList * l = malloc(sizeof(LinkedList));
	LinkedList * l2 = malloc(sizeof(LinkedList));
	l -> day = day;
	l2 -> day = day;
	l -> next = l2;

	export(l);
	
    return 0;
}
