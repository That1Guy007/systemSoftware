#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void main(){
	char x;
	while(1){
		scanf("%s", x);
		if(x >= '0' && x <= '9'){
			printf("X is a digit");
			break;
		}
	}
	exit(0);
}
