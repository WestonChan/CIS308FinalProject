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

Date * new_date(Event event[48], int day, Month month, int year) {
	if  (event == NULL || month == NULL || (day < 0 && day > 31) || year < 0) { return NULL;}
	
	Date * d = malloc(sizeof(Date));
	d->event = event;
	d->month = month;
	d->day = day;
	d->year = year;
	return d;
}

