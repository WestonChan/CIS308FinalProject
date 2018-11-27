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
Date * new_date(Event event[48], int day, Month month, int year) {
	if  (event == NULL || (day < 0 || day > 31) || year < 0) { return NULL;}
	
	Date * d = malloc(sizeof(Date));
	d->event = event;
	d->month = month;
	d->day = day;
	d->year = year;
	return d;
}

void toDateString(Date * day, char * string) {
	strcat(string, months1[day->month]);
	strcat(string, " ");
	char day1[3];
	sprintf(day1, "%d", day->day);
	strcat(string, day1);
	strcat(string, " ");
	char year1[5];
	sprintf(year1, "%d", day->year);
	strcat(string, year1);
}
