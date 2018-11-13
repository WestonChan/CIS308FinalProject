//
//  main.c
//  CIS 308 Project Final
//
//  Created by Weston Chan, Cale Povilonis, Damon Jones.
//

#include "Date.h"
#include "Event.h"

int main(int argc, const char * argv[]) {
	Event * e = new_Event("03:30", "04:30");
	printf("Hello World\n");
	printf("Start Time: %s\nEnd Time: %s\n", e -> start, e-> end);
    return 0;
}
