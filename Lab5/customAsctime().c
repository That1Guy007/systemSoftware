//this program mimics the acstime() function
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

char* myasctime(const struct tm *ptr){ // formats the data saved withing the time bffer
	int dow = ptr->tm_wday;//Use the overload operator b/c your are not using the struct directly you are calling it indirectly through another function
	int mon = ptr->tm_mon; //If you use the struct directly then you can the dot operator
	int Yr = ptr->tm_year + 1900;
	char* time = malloc(26); //saving the niformation into the time buf allocating 26 bytes of memory
	char* wDays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	char* Month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};x
	sprintf(time, "%s %s %i %i:%i:%i %d\n",wDays[ptr->tm_wday], Month[ptr->tm_mon], ptr->tm_mday, ptr->tm_hour, ptr->tm_min, ptr->tm_sec, Yr);
	return time;//time saves the string formated by sprintf()
}

void main(){
	int fd;
	char* ans;
	time_t T = time((time_t *)0);
	ans = myasctime(localtime(&T));
	printf("%s",ans);
	exit(0);
}
