#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv){ 
	int fd1, fd0, fdO;
	char txt;
        umask(0);
	fd1 = open(argv[1], 0);// 0 is equal to O_RDONLY = OPEN_READONLY
        fd0 = open(argv[2], 0);
	fdO = open("foo12", O_WRONLY | O_CREAT, 0760);
        while(read(fd0, &txt, 1) == 1) //while loop reads and write from input file 1 to output file char by char
                write(fdO, &txt, 1);
	lseek(fdO, -1, SEEK_CUR); //move offset back by one from the end which is the current offset
	while(read(fd1, &txt, 1) == 1) //while loop reads and writes from input file 2 and appends to output file
		write(fdO, &txt, 1);
        close(fd0); //close all files
        close(fd1);
	close(fdO);
        exit(0); //exit

}
