#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv){ //accepts command line arguments, keeps and argument counter and argument vector
	int fileDI, fileDO; //input and output file descripters
	char txt; // buffer size 1
	umask(0); //reset umask for file creation
	fileDI = open(argv[1], 0); //open first file passed
	fileDO = open("clone2", O_WRONLY | O_CREAT, 0770); //output file rwxrwx---
	while(read(fileDI, &txt, 1) ==1 ){ //read file
		write(fileDO, &txt, 1); //write char
	}
	close(fileDI); //close
	close(fileDO); //close
	exit(0);
}
