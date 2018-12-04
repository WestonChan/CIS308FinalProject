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

	char vars[3][21];
	//printTypes();
	for (int i = 0; i < 3; i++) {
		//printf("%s", returnTypes(i));
		strcpy(vars[i],returnTypes(i));
	}

	fprintf(fp,"%s^%s^%s", vars[0], vars[1], vars[2]);

	Event * events[72];
	int numEvents = 0;
	while(l != NULL) {
		fprintf(fp, "%d^%d^%d\n", l->day->day, l->day->month, l->day->year);
		for(int j = 0; j < 3; j++)
			for(int i = 0; i < 24; i++) {
				Event * e = l->day->event[j][i];
				if(e!= NULL) {
					int different = 1;
					for(int i = 0; i < numEvents; i++){
						//printf("%s\n", e->title);
						if(Equals(events[i], e) == 1) different = 0;}
					if(different == 1) {
						fprintf(fp, "%d^%d^%d^%s^%s", e->type, e->start, e->end, e->title, e->desc);
						events[numEvents] = e;
						numEvents++;
					}
				}
			}
		fprintf(fp,"\n");
		numEvents = 0;
		l = l->next;
	}
	fprintf(fp,"\n");
	fclose(fp);
	
}

LinkedList * import() {
	FILE * fp = fopen("Schedule.rofl", "r");
	char temp[DESCLENGTH + TITLELENGTH + 10 + 10];
	char * token;
	fgets(temp, DESCLENGTH + TITLELENGTH + 10 + 10, fp);
	
	char var1[21];
	char var2[21];
	char var3[21];
	token = strtok(temp, "^");
	strcpy(var1, token);

	token = strtok(NULL, "^");
	strcpy(var2, token);
	//printf("%s\n", token);
	token = strtok(NULL, "^");
	strcpy(var3, token);
	
	setTypeNames(var1,var2,var3);
	//printTypes();

	LinkedList * prev = NULL;
	LinkedList * first;

	Event * event[72];
	int numEvents = 0;
	int day, month, year;

	typedef enum LineType{Da, Ev}LineType;

	LineType lt = Da;
	while(fgets(temp, DESCLENGTH + TITLELENGTH + 10 + 10, fp) != NULL) {
		if(numEvents != 0 && strcmp(temp, "\n") == 0) {
			lt = Da;
			Event * events[3][24];
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 24; j++)
					events[i][j] = NULL;

			Date * d = new_date(events, day, month, year);
			for(int i = 0; i < numEvents; i++)
				addEvent(d, event[i]);

			numEvents = 0;

			LinkedList * cur = malloc(sizeof(LinkedList));
			cur -> day = d;

			if(first == NULL) first = cur; 
			if(prev == NULL) {
				prev = cur;
			}
			else {prev -> next = cur; prev = cur;}
		}
		else if(strcmp(temp, "\n") == 0) {}
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
		
		} else if (lt == Ev){("%s\n", temp);
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

int main(int argc, const char * argv[]) { 
/*
	Event * e = new_Event(2,3,24, "Lunch", "A midday meal.");

	printf("Hello World\n");
	printf("Start Time: %d\nEnd Time: %d\n", e -> start, e -> end);
	printf("Calendar is: %s\n\n",typeNames[e -> type]);

	char str[10000];

	Date * day = malloc(sizeof(Date));
	Event * events[3][24];	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 24; j++)
		events[i][j] = NULL;
	
	day = new_date(events, 02, August, 2016);

	addEvent(day, e);

	LinkedList * l = malloc(sizeof(LinkedList));
	LinkedList * l2 = malloc(sizeof(LinkedList));
	l -> day = day;
	l2 -> day = day;
	l -> next = l2;

	//export(l);*/

	LinkedList * ls = import();
	LinkedList * head = ls;
	while(ls != NULL) {
		char str[10000];
		printf("%s\n",toDateString(ls->day,str));
		ls = ls -> next;
	}	
	
	export(head);


	char help[] = {"Commands:\n\tExport\n\tAdd \n\tView\n\tHelp\n\tExit"};

	//LinkedList * ls = import();
	char * token;

	printf("Calendar Imported\n\n");
	printf("%s\n", help);

	do {
		LinkedList * mover = head;
		printf("\n\t\t>");
		char temp[1000];
		scanf("%s", temp);

		token = strtok(temp, " ");
		//printf("%s", token);
		if(strcmp(token, "Export") == 0) {
			export(head);
		} else if (strcmp(token, "Add") == 0) {
			printf("\n\t{EventName CalendarNumber(0-2) EventDescription StartTime(24Hr) EndTime(24Hr) Day/Month(0-11)/Year(DD/MM/YYYY}\n\n\t\t>");
			char eventname[50];
			int eventtype;
			char evdsc[50];
			int sint;
			int eint;
			int dayint;
			int monthint;
			int yearint;
			scanf("%s %d %s %d %d %d/%d/%d", eventname, &eventtype, evdsc, &sint, &eint, &dayint, &monthint, &yearint);

			//printf("%s,%s,%s,%s,%s,%s,%s,%s,%s", eventname, etype, evdsc, stime, etime, timetime, daysplit, month, year);	
	
			Event * newevent = new_Event(eventtype, sint, eint, eventname, evdsc);
			int found = 0;
			LinkedList * temph = head;
			while(temph != NULL) {
				if (dateEquals(temph->day, dayint, monthint, yearint)==0) {
					addEvent(temph->day, newevent);
					found = 1;
				}
				temph = temph->next;
			}
			if (found == 0) {
				Date * day;
				Event * events[3][24];	
				for(int i = 0; i < 3; i++)
				for(int j = 0; j < 24; j++)
				events[i][j] = new_Event(0,0,0,"","");
	
				day = new_date(events, dayint, monthint, yearint);

				addEvent(day, newevent);

				

				LinkedList * newNode = malloc(sizeof(LinkedList));
				newNode->day = day;
				newNode ->next = head;
				head = newNode;
				//temph->next = newNode;
				/*char tstr[1000];
				toDateString(temph->day, tstr);
				printf("%s", tstr);*/
			}
		} else if (strcmp(token, "View") == 0) {
			printf("\n\tType the Date (Day/Month/Year) or search EventName\n\n\t\t>");
			char newtemp[1000];
			scanf("%s",newtemp);
			char * day = strtok(newtemp, "/");
			char * month = strtok(NULL, "/");
			if (month != NULL) {
				char * year = strtok(NULL, "/");
				//printf("%s/%s/%s",day,month,year);

				if(day != NULL && month != NULL && year != NULL) {
					while(dateEquals(mover->day, atoi(day), atoi(month), atoi(year)) != 0 && mover->next != NULL)
						mover = mover->next;
					if(dateEquals(mover->day, atoi(day), atoi(month), atoi(year)) == 0) printf("%s\n", toDateString(mover->day,temp));
					else printf("Date not found.\n");
				}
			}
			else {	int found = 0;
				LinkedList * temph = head;
				while(temph != NULL) {
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 24; j++) {
							if ((found==0)&&temph->day->event[i][j]!= NULL && (strcmp(day, temph->day->event[i][j]->title)==0)){
								printf("%s\n", toEventString(temph->day->event[i][j],temp)); found = 1;}
						}
					}
				temph = temph->next;
				}
			}
			//else {a
			//	day = 
			//}
		} else if (strcmp(token, "Help") == 0) {
			printf("%s\n", help);
		}
	}while(strcmp(token, "Exit") != 0);

    return 0;
}
