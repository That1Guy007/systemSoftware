//this program opens the utmp file
#include <stdlib.h>
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>

int openUtmpFile(){
	int fd = open("/var/run/utmp", 0);
	if(fd < 0 ){
		printf("Error opening file");
		exit(1);
	}
	return fd;
}

void main(){
	openUtmpFile();
	printf("utmp file opened \n");
	exit(0);
}
