/*
	Write a program to simulate the clock
	1. Write a struct to represent Clock (h:m:s)
	2. Implement following functions for Clock
		increment								// increments the input Clock element
		show									// print the input Clock element with a nice format
	3. Test your functions in main
	+ By simulating a time period For example simulate for 10 seconds
	+ Does not need to do it in real time
*/

#include <stdio.h>
#include <stddef.h> // size_t

#define SIMULATE	7200
#define LIM_60		60
#define LIM_24		24

typedef struct{
	int second;
	int minute;
	int hour;
} Clock;

void increment(Clock* clock){
	// Increment second
	if (clock->second == LIM_60 - 1){				// If the second is maximum, set second as 0 & change the minute
		clock->second = 0;
		
		// Increment minute
		if (clock->minute == LIM_60 - 1){			// If the minute is maximum, set minute as 0 & change the hour
			clock->minute = 0;
			
			// Increment hour
			if (clock->hour == LIM_24 - 1)			// If the minute is maximum, set hour as 0
				clock->hour = 0;
			else
				(clock->hour)++;
		}
		else
			(clock->minute)++;
	}
	else
		(clock->second)++;
}

void show(Clock* clock){
	printf("%02d:%02d:%02d\n", clock->hour, clock->minute, clock->second);
}

int main(){
	// Generate a new struct
	Clock hour_24 = {0, 0, 0};
	Clock* ptr_hour_24 = &hour_24;
	
	for (size_t i = 0; i <= SIMULATE; i++){
		show(ptr_hour_24); 
		increment(ptr_hour_24);
	}
	
	return 0;
}