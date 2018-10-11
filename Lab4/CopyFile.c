#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//access a file and copy, Tests for existence
int main(int argc, char ** argv){
	int fd1, fd2;
	char txt;
	if(access(argv[1],F_OK) < 0){ //acces test the existance or permission of a file. F_OK test for existance
		printf("Error, Input file does not exist");
		exit(1);
	}
	fd1 = open(argv[1],0); //opens file passed
	fd2 = open(argv[2],O_WRONLY | O_CREAT, 0660);//opens 2nd file passed
	while(read(fd1,&txt,1) >0){ //reads first file
		write(fd2, &txt,1);//writes to second file
	}
	exit(0);
}
