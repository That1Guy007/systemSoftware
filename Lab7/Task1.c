//this program usesa child to send the sigalarm signal to the parent which the signal's handler is changed using sigaction structure
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int alarm_fired = 0; // bascally a boool val

void ding(int sig){ // new handler
	alarm_fired = 1;
}

int main(){
	pid_t pid;
	struct sigaction act; // structure of sigaction
	memset(&act, 0 ,sizeof(act)); // clear the space
	act.sa_handler = ding; // set the handler to use ding()
	printf("alarm application starting\n");
	pid = fork(); //child created
	switch(pid) {
		case -1:
		/* Failure */
			perror("fork failed");
			exit(1);
		case 0:
		/* child */
			sleep(5);
			kill(getppid(), SIGALRM); // kill sends a signa to  ppid whihc is parent
			exit(0);
		}
		/* if we get here we are the parent process */
	printf("waiting for alarm to go off\n");
	//(void) signal(SIGALRM, ding);
	sigaction(SIGALRM,&act,NULL);// set the action of sigalarm to use the struct of sigaction 'act' which has the handler ding()
	pause(); // pause waits for a signal
	if (alarm_fired) // if 1 basically
		printf("Ding!\n"); // print ding
	printf("done\n");
	exit(0);
}
