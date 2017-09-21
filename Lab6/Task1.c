#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;//environ variable which basically holds the environment variables

char* mygetenv(const char *name){ // this function uses the environ variable which is char **  or a [][] bsically and grabs the requested environment var
	int i=0;
	int x = 0;
	int con = 0;

	while (environ[x]!= NULL){//goes though the list of environ variables
		i = 0;
		while(environ[x][i]== name[i]){//compares the first character of the passed environ variable to the pointers first char of the enivron var
			if(environ[x][i+1] == '='){ //if it comes to an = then you have found the environ var so break out of looop
				con = 1;
				break;
			}
			i++;
		}
		if(con == 1)
			break;//break out
		x++;//else look at the next enviro n variable
	}
	return environ[x];//return the pointer to the ENV string
}

void main(int argc, char** argv){
	if(argv[1] == NULL){//pass in an environ varible
		printf("Please pass the ENV variable ud like to see:\n");
		exit(1);
	}
	char* ans  = mygetenv(argv[1]); // save the returned pointer into ans
	printf("%s\n", ans);//print ans pointers info
	exit(0);

}
