//
//  Date.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char months1[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
Date * new_date(Event * event[3][24], int day, Month month, int year) {
	if  (event == NULL || (day < 0 || day > 31) || year < 0) { return NULL;}
	
	Date * d = malloc(sizeof(Date));
	d->event[0][0] = event[0][0];
	d->month = month;
	d->day = day;
	d->year = year;
	return d;
}

Date * addEvent(Date * day, Event * e) {
	if(day == NULL || e == NULL) return NULL;
	if(e->start < 0 || e->end > 24) return NULL;
	int time = e->start;	
	while(time < e->end){
		day->event[e -> type][time] = e;
		time++;
	}
}

char * toDateString(Date * day, char * str) {
	if(day == NULL || str == NULL) return "";
	str[0] = '\0';
/*
	strcat(string, months1[day->month]);
	strcat(string, " ");
	char day1[3];
	sprintf(day1, "%d", day->day);
	strcat(string, day1);
	strcat(string, " ");
	char year1[5];
	sprintf(year1, "%d", day->year);
	strcat(string, year1);
*/

	char title[TITLELENGTH];
	
	strcat(str, "     \t");
	
	for(int i = 0; i < 3; i++) {
		strcpy(title, typeNames[i]);
		while(strlen(title) != TITLELENGTH - 1) {
			strcat(title, " ");
		}
		strcat(str, title);
		strcat(str, "\t");
	}
	
	strcat(str, "\n\n");

	char tempstr[2];
	
	for(int i = 0; i < 24; i++) {
		if(i <= 9)strcat(str, "0");
		sprintf(tempstr, "%d", i);
		strcat(str, tempstr);
		strcat(str, ":00\t");
		
		for(int j = 0; j < 3; j++) {
			if(day->event[j][i] == NULL) 
				for(int k = 0; k < TITLELENGTH-1; k++)
					strcat(str, " ");
			else {
				strcpy(title, day -> event[j][i] ->title);
				while(strlen(title) != TITLELENGTH - 1) {
					strcat(title, " ");
				}
			strcat(str, title);
			}
		strcat(str, "\t");
		}
	strcat(str, "\n");
}
	

return str;
}
