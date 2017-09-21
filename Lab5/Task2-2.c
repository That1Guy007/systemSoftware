//this program opens the utmp file and then prints out the user and the type and counts the number of users
#include <stdlib.h>
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int openUtmpFile(){
        int fd = open("/var/run/utmp", 0);
        if(fd < 0 ){
                printf("Error opening file");
                exit(1);
        }
        return fd;
}

void main(){
	int fd, count = 0;
        fd = openUtmpFile();
        printf("utmp file opened \n");
	struct utmp tmp;//tmp is the buffer
	int bufflen = sizeof(tmp);		//or sizeof(struct utmp) works
	while(read(fd,&tmp,bufflen) > 0){
		printf("-- %s 	--%d\n",tmp.ut_user, tmp.ut_type);
		if(tmp.ut_type == 7)
			count++;
	}
	printf("There are currently only %d users logged in.\n", count);
	close(fd);
        exit(0);
}

