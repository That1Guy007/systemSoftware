#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int StoI(char* str){
        int result = 0;
        for(int i = 0; i<strlen(str);i++)
                result = result* 10 + (str[i] - '0');
        return result;
}

void main(int argc, char** argv){
	int i = 0;
	pid_t pid;
	for(i;i < StoI(argv[1]);i++){
		printf("This is the child: %d\n", pid);
		sleep(StoI(argv[3]));
	}
}
