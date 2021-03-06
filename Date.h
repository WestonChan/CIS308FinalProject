//
//  Date.h
//  Week 8 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef Date_h
#define Date_h
#include "Event.h"
#include <stdio.h>


typedef enum Month {January, February, March, April, May, June, July, August, September, October, November, December} Month;

typedef struct Date {
	Event * event[3][24];
	int day;
	Month month;
	int year;
} Date;

Date * new_date(Event * event[3][24], int day, Month month, int year);

Date * addEvent(Date * day, Event * e);

char * toDateString(Date * day, char * str);

int dateEquals(Date * day1, int day, int month, int year);
#endif /* Date_h */
