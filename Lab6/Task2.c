//this program creates a child and accepts two command line arguments which are used to pause between the messages
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StoI(char* str){
	int result = 0;
	for(int i = 0; i<strlen(str);i++)
		result = result* 10 + (str[i] - '0');
	return result;
}

int main(int argc, char** argv)
{
	pid_t pid; // holds the process id of the programs
	char *message; // the char poointer to hold the message
	int n;
	printf("fork program starting\n");
	pid = fork(); //fork creats a child and save the pid
	switch(pid) // takes the pid and if the pid is 0 then its the child and execute child code
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = StoI(argv[1]);
			break;
		default: // else its the parent
			message = "This is the parent";
			n = StoI(argv[2]);
			break;
	}
	for(; n > 0; n--) {
		puts(message);
		if(pid == 0)
			sleep(StoI(argv[3]));
		else
			sleep(StoI(argv[4])); //sleeps for a number of seconds and prints n times which is hanf=dled by the appropraite program, chld or parent
	}
	exit(0);
}
