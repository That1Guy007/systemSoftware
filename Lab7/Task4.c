//this program has 2 children which both send signals to the parent and then they are handled using the handler defined using signal system call
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler (int signo){
	if(signo == SIGUSR1)
		printf("HI honey!, Anything wrong?\n");
	else if (signo == SIGUSR2)
		printf("Do you make trouble again?\n");
	else
		printf("Error");
}

void main (){
	pid_t pid, pid2;
	pid = fork();
	if(pid != 0){
		pid2 = fork();
		//printf("%d", pid2);
	}
	int status;
	if(pid == 0){
		sleep(1);
		kill(getppid(), SIGUSR1);
	}
	else{
		signal(SIGUSR1,sig_handler);//signal system call (signal, and handler)
		pause();
	}//signal(SIGUSR1, sig_handler);
	if(pid2 == 0){
		sleep(1);
		kill(getppid(), SIGUSR2);
	}//signal(SIGUSR2, sig_handler);
	else{
		//wait(&status);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	exit(0);
}
