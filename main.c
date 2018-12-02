//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdlib.h>
#include "Date.h"
#include "Event.h"


void sendToFile(Date * day) {
	FILE * fp = fopen("Schedule.txt","w");
	char str[4000];
	fprintf(fp,"%i %s %i\n%s\n", day->day, getMonth(day), day->year, toDateString(day,str));
	fclose(fp);
}





int main(int argc, const char * argv[]) {
	setTypeNames("Calendar0", "Calendar1", "Calendar2");
	Event * e = new_Event(2,3, 4, "Lunch", "A midday meal.");

	printf("Hello World\n");
	printf("Start Time: %d\nEnd Time: %d\n", e -> start, e-> end);
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

	sendToFile(day);
	
    return 0;
}













/*
#include <stdlib.h>
#include <stdio.h>
//#include "Date.h"
#include "Event.h"



int main(int argc, const char * argv[]) {
	//Date * day = malloc(sizeof(Date));

	printf("Enter the names of your (3) calendar types. Press Enter after naming each calendar.");
	char c1 [TYPELENGTH];
	char c2 [TYPELENGTH];
	char c3 [TYPELENGTH];
	printf("\nCalendar 1: \t");
	fgets(c1, TYPELENGTH, stdin);
	printf("\nCalendar 2: \t");
	fgets(c2, TYPELENGTH, stdin);
	printf("\nCalendar 3: \t");
	fgets(c3, TYPELENGTH, stdin);
	setTypeNames(c1, c2, c3);
	Event * e = new_Event(0,"03:30", "04:30", "Lunch", "");

	//printf
	char*

//	printf("Hello World\n");
//	printf("Start Time: %s\nEnd Time: %s\n", e -> start, e-> end);
//	printf("Calendar is: %s\n",typeNames[e -> type]);
    return 0;
}*/
