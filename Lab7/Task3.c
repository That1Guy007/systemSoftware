//this program writes hi mom to a file then the parent reads the file without closeing and reopening so it must lseek and then prints out when the child said
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	pid_t pid;
	pid = fork();
	int status;
	char txt[8] = "Hi, Mom\n";
	int fd1 = open("foo", 2 | O_CREAT, 0755); //2 sets it to RW ... file needs to be written to and read form
	if(pid == 0){
        	write(fd1, &txt, 8);
		close(fd1);
	}
	else{
		wait(&status);
		char txt1[8];
		if(lseek(fd1, 0 ,SEEK_SET) == -1)
			printf("issues");
		if(read(fd1, &txt1, 8) == -1)
			printf("failing");
		write(0,"My son said ", 12);
		write(0, &txt1, 8);
		//printf("Working\n");
	}
	close(fd1);
	exit(0);
}
