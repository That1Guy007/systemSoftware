//this program does the same as task 2, but also demonstrates the exit code. when a child executes it sends a status and exit code to it parent
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StoI(char* str){ // converts str to int by  subtracting the number from char 0
	int result = 0;
	for(int i = 0; i<strlen(str);i++)
		result = result* 10 + (str[i] - '0');
	return result;
}

int main(int argc, char** argv)
{
	pid_t pid; // holds pid
	char *message;
	int n;
	printf("fork program starting\n");
	pid = fork(); // crerates child
	int exit_code; //holds the exit code for the programs, this is uninitialized data
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = StoI(argv[1]); // converts string into an int and uses that to repeat a msg n times
			exit_code = 37;//exit code 37
			break;
		default:
			message = "This is the parent";
			n = StoI(argv[2]);//same as chold
			exit_code = 0; //exit code 0 all good
			break;
	}
	for(; n > 0; n--) {
		puts(message); //prints message
		if(pid == 0)
			sleep(StoI(argv[3]));
		else
			sleep(StoI(argv[4]));
	}
	if (pid != 0) {
		int stat_val;
		pid_t child_pid; // holds a pid
		child_pid = wait(&stat_val); //parent waits for a child to execute and then grabs the childs pid from the waits return
		printf("Child has finished: PID = %d\n", child_pid); // print info
	if(WIFEXITED(stat_val)) //print their exit code
		printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
	else
		printf("Child terminated abnormally\n");
	}
	exit(exit_code);
}
