#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int h, m, s;
int mode;
	
int main() {
	printf("Select 12hr/24hr: ");
	scanf("%d", &mode);
	
	if (mode != 12 && mode != 24) {	//Checks whether mode is set to either 12 or 24 hour clock
		printf("ERROR: Invalid clock\n");
		return 0;
	}
	
	printf("Separate hours, minutes, and seconds with spaces (12 00 00) = (h, m, s)\n");
	printf("Set Time (%d hour clock): ", mode);  //Set time
	scanf("%d %d %d", &h, &m, &s);
	if (mode == 24 && h > 23) {		//Check hours (24)
		printf("ERROR: Invalid Hour\n");
		return 0;
	}
	if (mode == 12 && h > 12) {		//Check hours (12)
		printf("ERROR: Invalid Hour\n");
		return 0;
	}
	if (m > 59) {		//Check minutes
		printf("ERROR: Invalid Minutes\n");
		return 0;
	}
	if (s > 59) {		//Check seconds
		printf("ERROR: Invalid seconds\n");
		return 0;
	}
	
	while (1) {
		system("clear");		//Clears screen
		printf("\n%02d:%02d:%02d\n", h, m, s);
		fflush(stdout);		//Clear stdout buffer
		s++;		//Increments seconds
		if (s > 59) {		//Increments minutes; sets seconds to 0
				m += 1;
				s = 0;
		}
		if (m > 59) {		//Increments hours; sets min to 0
				h += 1;
				m = 0;
		}
		if (h > 12 && mode == 12) {		//Resets all (12 hr clock)
				h = 1;
				m = 0;
				s = 0;
		} else if (h > 23 && mode == 24) {		//Resets all (24 hour clock)
				h = 0;
				m = 0;
				s = 0;
		}
		
		sleep(1);		//1 second delay

	}
	return 0;
}
