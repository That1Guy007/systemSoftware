//This program deals with race condition
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include<unistd.h>

int myIsdigit(char iNum){ //my own s digit function could be better using ''?''
	int bVal = 0;
	if(iNum >= '0' && iNum <= '9'){
		bVal =1;
	}
	return bVal;
}

void main(int argc, char ** argv){
	pid_t pid;
	pid = fork(); // creates child
	int fd = open(argv[1], 0); // open a file passed as an arg
	int counter1 = 0; // these counter keep track of the reads location for the parent and child
	int counter2 = 0;
	if(pid== -1){
		perror("fork failed");
		exit(1);
	}
	if(pid == 0){
		char txt; //buffer for reading
		int fd1 = open("child.txt", O_WRONLY | O_CREAT, 0755);
		while(lseek(fd, counter1, SEEK_SET) != -1 && read(fd, &txt, 1) >0){ // resets the location of the cursor  each time in order to prevent alteration from the parent
			counter1++;// increase counter to know where you are
			if (myIsdigit(txt) == 1) // use my isdigit
				write(fd1, &txt, 1);
		}
		close(fd1); // close when done
	}
	else{
     	       	char txt1; // buffer for reading
		int fd2 = open("parent.txt", O_WRONLY | O_CREAT, 0755); // open file for input
		while(lseek(fd,counter2,SEEK_SET) != -1 && read(fd,&txt1,1)>0){ // lseek and read
			counter2++;
			if(myIsdigit(txt1) == 0) // if its not a number put it into the parent tcxt file
				write(fd2, &txt1, 1);
		}
		close(fd2);
		//reading for parent
	}
	exit(0);
}
