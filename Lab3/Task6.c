#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

//Palindrome program

int palind(int fd1, int fd2){ //function that tests for a palondrome, accepts two file descripters
	int val, counter, counter1;//two counters for two lseeks
	char txt, txti;//two buffers for both files
	counter = 2; //moves cursor from the end back two
	counter1 = 0; //keeps track of the cursor of the front
	val=0; //if  0 then it is not a palindrome if 1 then it is a palindrome
	while((lseek(fd1, -counter, SEEK_END) != -1)  && (read(fd1, &txt, 1) != -1) && (lseek(fd2,counter1,SEEK_SET)!=-1) && (read(fd2, &txti, 1)!= -1)){
		//printf("working?");
		if(txt != txti){ //if the buffers are not correct then break out of the function and return the value which determines the palindrome or not
			val = 1;
			//printf("%c and %c",txt,txti);
			break;
		}
		counter++;
		counter1++;
	}
	return val;
}

int main (int argc, char **argv){
        int fd0, fd1, test;
        fd0 = open(argv[1], 0);
        fd1 = fd0;
	test = palind(fd0, fd1);
        close(fd0);
        close(fd1);
	if(test == 1){
		printf("Not a palindrome \n");
	}
	else
		printf("Plaindrome detected\n");
        exit(0);
}
