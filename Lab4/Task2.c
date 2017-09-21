
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

//adds the sum of the arguments passed

int convStrToInt(char * s){
	return (s -'0');//strtol(s,NULL,10)); //formats string to a number in base 10, until null is found
}

int main( int argc, char * argv[]){
	int sum= 0;
	int exist = 1;
	if(argc == 1){
		printf("Error, There was no numbers passed\n");
		exit(1);
	}
	for(int i = 1; i<argc; i++)
		sum = sum + convStrToInt(argv[i]);//goes through each argument passed, converts to integer from a string and sums them.
	printf("Sum of arguments is : %d\n",sum);//prints sum
	exit(0);
}
