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
Date * new_date(Event * event[24], int day, Month month, int year) {
	if  (event == NULL || (day < 0 || day > 31) || year < 0) { return NULL;}
	
	Date * d = malloc(sizeof(Date));
	d->event[0] = event[0];
	d->month = month;
	d->day = day;
	d->year = year;
	return d;
}

Date * addEvent(Date * day, Event * e) {
	int time = e->start[0]-'0';	
	while(time < e -> end[0]-'0'){
		day->event[time] = e;
		time ++;
	}
}

char * toDateString(Date * day, char * str) {
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
	char tempstr[2];
	for(int i = 0; i < 24; i++) {
		if(i <= 9)strcat(str, "0");
		sprintf(tempstr, "%d", i);
		strcat(str, tempstr);
		strcat(str, ":00\t");
		
		char title[TITLELENGTH];
		strcpy(title, day -> event[i] ->title);
		while(strlen(title) != TITLELENGTH - 1) {
			strcat(title, " ");
		}
		strcat(str, title);

		strcat(str, "\n");
	}
	return str;
}
