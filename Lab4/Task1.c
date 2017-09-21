#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char* convIntToStr(char * str, int x){//converts int to Cstring
	sprintf(str, "%d", x);//this takes X which is  of type %d and puts it into the str buffer
	return str;//returns the char* str
}

void append(char* s, char c){ //appends each found number to char array (string)
	int len = strlen(s);//len holds the length of s
	s[len] = c;//the last character is appended to s
	s[len+1] = '\0';//adds EOF to the end of the char/string
}

int convStrtoInt(char * str){ // converts string to integer
	int result =0;	//this converters string to integer value by converting ascii to integer numbers
	for(int i = 0; i<strlen(str);i++){ //for loop goes through the Cstring and converts each element into its integer value. 
		result = result * 10 + (str[i] - '0');	//multiplies the number by ten to move it over
	}
	//return (strtol(str,NULL,10));
	return result;	//returns the argument string into an integer value.
}

int main(int argc, char ** argv){
	int fd;
	char txt;
	char ans[80];
	int num;
	if(argv[1] == NULL){ // looks for a passed in argument from cmd line
		printf("Error did not pass in file\n");
		exit(1);
	}
	fd = open(argv[1], 0);//fd holds the file descriptor for the passed in file name or path
	while(read(fd,&txt,1) >0){ //reads 1 char at a time tests that char and then appends or ignore it
		if(isdigit(txt)){//checks if it is a digit
			append(ans,txt);//calls the append function
		}
	}
	num = convStrtoInt(ans);//sends the string into the converter to make it and integer
	num = num + 10;//adds ten to it
	printf("number is :  %s\n",convIntToStr(ans, num));
	close(fd);//close the file
	exit(0);

}
