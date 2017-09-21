#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char ** argv){
	int fd1, fd2; //two file descripters
	char txt; //buffer size one
	umask(0); //reset umask for file creation to set mode
	mkdir("/home/that1guy/Dir1", 0755); //make directory
	mkdir("/home/that1guy/Dir2", 0755); //make directory
	mkdir("/home/that1guy/Dir2/Dir21", 0755);//make directory
	fd1 = open("/home/that1guy/Documents/350/Lab4/hello", 0);//open test file called hello for readonly
	fd2 = open("/home/that1guy/Dir2/Dir21/hello", O_WRONLY | O_CREAT, 0770);//open or creat hello in new directory
	if(fd2 == -1){ //check for error
		printf("error");
		exit(1);
	}
	while(read(fd1,&txt,1)>0){ //read from fd1
		write(fd2,&txt,1);//write to fd2
		//printf("k");
	}
	symlink("/home/that1guy/Dir2/Dir21", "/home/that1guy/Dir1/toDir21");//symbolic link
	symlink("/home/that1guy/Dir2/Dir21/hello", "/home/that1guy/Dir1/toHello"); //symbolic link
	exit(0);
}
