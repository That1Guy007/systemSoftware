#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char **argv){
        int fd0, fdO;
        char txt;
        fd0 = open(argv[1], 0);
        fdO = open("foorev", O_WRONLY | O_CREAT, 0760);
	int counter = 1;//counter to move the cursor of the file backwards by 1 after each iteration.
        while(lseek(fd0, -counter, SEEK_END) != -1 && read(fd0, &txt, 1) == 1 ){ //whle loop set cursor to the end and back one to ignore the newline char
		write(fdO, &txt, 1); //after ignoreing newline char read char there and write to file
		counter++; //increase how far back you want to go from the end and repeat until you cant go back any further
	}
        close(fd0);//close all files
        close(fdO);
        exit(0);
}
