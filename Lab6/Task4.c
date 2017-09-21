//same as task2 and task3 but uses execv ** should be using execl
#include <sys/wait.h>
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
	pid_t pid;
	char *message;
	int n;
	printf("fork program starting\n");
	pid = fork();
	int exit_code;
	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			if(execv("/home/that1guy/Documents/350/Lab6/child", argv));//(char* []){ "Thiss is the chile", argv[1], argv[3]}))
			{//USE EXECL instead
				printf("FAILLING");
				exit(0);
			}
			/*message = "This is the child";
			n = StoI(argv[1]);
			exit_code = 37;*/
			break;
		default:
			message = "This is the parent";
			n = StoI(argv[2]);
			exit_code = 0;
			break;
	}
	for(; n > 0; n--) {
		printf("%s PID: %d \n",message, pid);
		if(pid == 0)
			sleep(StoI(argv[3]));
		else
			sleep(StoI(argv[4]));
	}
	if (pid != 0) {
		int stat_val;
		pid_t child_pid;
		child_pid = wait(&stat_val);
		printf("Child has finished: PID = %d\n", child_pid);
	if(WIFEXITED(stat_val))
		printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
	else
		printf("Child terminated abnormally\n");
	}
	exit(exit_code);
}
