//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdlib.h>
#include <string.h>
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
	char temp[999999999999];
	char * token;
	fscanf(fp, "%s", temp);

	token = strtok(temp, "^");
	strcpy(typeNames[0], token);

	token = strtok(NULL, "^");
	strcpy(typeNames[1], token);

	token = strtok(NULL, "^");
	strcpy(typeNames[2], token);
	
	LinkedList * prev = NULL;
	LinkedList * first;
	int line = -1;
	Event * event[3][24];
	int day, month, year;
	
	while(fscanf(fp, "%s", temp) != EOF) {/*
		if(line == -1){
			token = strtok(temp, "^");
			day = atoi(token);

			token = strtok(NULL, "^");
			month = atoi(token);

			token = strtok(NULL, "^");
			year = atoi(token);

		
		} else if (line >= 0){
				token = strtok(temp, "^");
				int type = atoi(token);
	
				token = strtok(NULL, "^");
				int start = atoi(token);
	
				token = strtok(NULL, "^");
				int end = atoi(token);
	
				token = strtok(NULL, "^");
				char title[TITLELENGTH];
				strcpy(title, token);

				token = strtok(NULL, "^");
				char desc[DESCLENGTH];
				strcpy(desc, token);

				Event * e = new_Event(type, start, end, title, desc);
	
				event[type][line%24] = e;

			}*/
		
		if(line == 71) {
			LinkedList * cur = malloc(sizeof(LinkedList));
			Date * d = new_date(event, day, month, year);
			cur -> day = d;
			line = -2;
			if(prev == NULL) first = cur;
			if(prev != NULL) prev = prev -> next;
				prev = cur;
			
		}
		else line++;
	}
	fclose(fp);
	return first;
	LinkedList * cur = malloc(sizeof(LinkedList));
return cur;
}

int main(int argc, const char * argv[]) {/*
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

	export(l);*/
	LinkedList * l = import();
	while(l != NULL) {
		char str[10000];
		toDateString(l -> day, str);
		l = l -> next;
		printf("%s\n", str);
	}	
	
    return 0;
}
