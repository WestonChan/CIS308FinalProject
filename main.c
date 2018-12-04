//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Date.h"
#include "LinkedList.h"


void export(LinkedList * l) {
	FILE * fp = fopen("Schedule.rofl", "w");

	fprintf(fp,"%s^%s^%s\n", typeNames[0], typeNames[1], typeNames[2]);

	Event * events[72];
	int numEvents = 0;
	while(l != NULL) {
		fprintf(fp, "%d^%d^%d\n", l->day->day, l->day->month, l->day->year);
		for(int j = 0; j < 3; j++)
			for(int i = 0; i < 24; i++) {
				Event * e = l->day->event[j][i];
				if(e!= NULL) {
					int different = 1;
					for(int i = 0; i < numEvents; i++)
						if(Equals(events[i], e) == 0) different = 0;
					if(different == 1) {
						fprintf(fp, "%d^%d^%d^%s^%s\n", e->type, e->start, e->end, e->title, e->desc);
						events[numEvents] = e;
						numEvents++;
					}
				}
			}
		fprintf(fp,"\n");
		numEvents = 0;
		l = l->next;
	}
	fclose(fp);
	
}

LinkedList * import() {
	FILE * fp = fopen("Schedule.rofl", "r");
	char temp[DESCLENGTH + TITLELENGTH + 10 + 10];
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

	Event * event[72];
	int numEvents = 0;
	int day, month, year;

	typedef enum LineType{Da, Ev}LineType;

	LineType lt = Da;
	while(fscanf(fp, "%s", temp) == 1) {
		if(numEvents != 0 && strcmp(temp, "")) {
			lt = Da;
			Event * events[3][24];
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 24; j++)
					events[i][j] = NULL;

			Date * d = new_date(events, day, month, year);
			for(int i = 0; i < numEvents; i++)
				addEvent(d, event[i]);
char str[10000];
printf("%s\n",toDateString(d,str));
			numEvents = 0;

			LinkedList * cur = malloc(sizeof(LinkedList));
			cur -> day = d;

printf("%s\n",toDateString(cur->day,str));
			if(first == NULL) first = cur; 
			if(prev == NULL) {
				prev -> next = cur;
				prev = cur;
			}
			else prev = cur;
		}
		else if(strcmp(temp, "")) {}
		else if(lt == Da){
			lt = Ev;
			token = strtok(temp, "^");

			if(token == NULL) day = 0;
			else day = atoi(token);

			token = strtok(NULL, "^");
			if(token == NULL) month = 0;
			else month = atoi(token);

			token = strtok(NULL, "^");
			if(token == NULL) year = 0;
			else year = atoi(token);

		
		} else if (lt == Ev){
				if(strcmp(temp,"^^^^") == 0) continue;

				token = strtok(temp, "^");
				int type;
				if(token == NULL) type = 0;
				else type = atoi(token);
	
				token = strtok(NULL, "^");
				int start;
				if(token == NULL) start = 0;
				else start = atoi(token);
	
				token = strtok(NULL, "^");
				int end;
				if(token == NULL) end = 0;
				else end = atoi(token);
	
				token = strtok(NULL, "^");
				char title[TITLELENGTH];
				if(token == NULL) strcpy(title, "");
				else strcpy(title, token);

				token = strtok(NULL, "^");
				char desc[DESCLENGTH];
				if(token == NULL) strcpy(desc, "");
				else strcpy(desc, token);
				
				event[numEvents] = new_Event(type, start, end, title, desc);
				numEvents++;
			}
	}
	fclose(fp);
	return first;
}

int main(int argc, const char * argv[]) { /*

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
*/
	char str[10000];
	LinkedList * ls = import();
	if(ls != NULL)
	printf("%s\n",toDateString(ls->day,str));

	while(ls != NULL) {
		char str[10000];
		printf("%s\n",toDateString(ls->day,str));
		ls = ls -> next;
	}	
	
    return 0;
}
