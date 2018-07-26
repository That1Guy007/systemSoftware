#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){ //accepts command line arguments
        int fileDI, fileDO; //file descripter 1 and descripter 2
        char txt; //buffer size 1
        umask(0); //reset umask temporarily to allow for proper mode on creation
	fileDI = open(argv[1], 0); //open passed file, obtain file descripter
        fileDO = open("clone1", O_WRONLY | O_CREAT, 0666); // open or create clone1 with mode 666 = RW-RW-RW-
        while(read(fileDI, &txt, 1) ==1 ){ // while reading the file char by char with no errors
                write(fileDO, &txt, 1); //write  to the output file (2nd file descripter) what you read
        }
        close(fileDI); // close input file
        close(fileDO); //close output file
        exit(0); //exit
}
