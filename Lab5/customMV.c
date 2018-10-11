//this program mimics the mv command by linking a file into another directory and then unlinking it from the previous directory
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void main(int argc, char ** argv){
	struct stat buff; //creates a structure of the stat named buff
	if(stat(argv[2], &buff) < 0){ //throws the 2nd passed argument which is either a file or directory into the struct named buff
		printf("Struct stat error");
		exit(1);
	}
	if(S_ISDIR(buff.st_mode)){ //uses the s_isdir macro to test if the passed string was a directory or not.
		printf("Moving %s to %s \n", argv[1] , argv[2]); // if so then moves the first argu to the directory
		if(link(argv[1],argv[2]) < 0)// link
			printf("error\n");
		unlink(argv[1]);//Unlink
		exit(0);
	}
	else{
		printf("Moving %s to %s \n", argv[1], argv[2]);// if not then move the file into the directory in argv[1]
		if(link(argv[1],argv[2]) < 0)//Link
			printf("error\n");
		unlink(argv[1]);//Unlink
		exit(0);
	}
}
