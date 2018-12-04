#ifndef LinkedList_h
#define LinkedList_h

#include <stdlib.h>
#include "Date.h"
#include "Event.h"

typedef struct LinkedList{
	Date * day;
	struct LinkedList * next;
}LinkedList;

#endif
