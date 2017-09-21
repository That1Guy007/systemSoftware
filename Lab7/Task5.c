//this program blocks both cntrl c and cntrl \ then opens up cntrl c so that you may terminate the program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void handler(int sig){
	if (sig == SIGINT)
		printf("INT unblocked, but handled");
	else if (sig == SIGQUIT)
		printf("QUIT unblocked, but handled");
}

void main(){
	int i;
	sigset_t set, old; // this creates a set for the signals which you want to add or remove
	struct sigaction act; //holds flags and handler info
	memset (&act, 0, sizeof(act)); // clears the memory of the struct
	sigemptyset(&set); //clears the set and allows everything
	sigaddset(&set, SIGINT); //add sigint into the set
	sigaddset(&set, SIGQUIT); //adds sigquit into the set
	act.sa_handler = handler;// assigns a handler
	if(sigaction(SIGINT, &act, 0))// tell the signal what you want it to do by assigning it to the struct of sigaction
		printf("ACTION FAIL");
	sigaction(SIGQUIT, &act, 0);
	if(sigprocmask(SIG_BLOCK, &set, NULL) <0) // tells the program to block the created set of signals
		printf("FAILING");
	for(i = 1; i<6; i++){ // go through 0-5 with both signals blocked
		printf("%d\n",i);
		sleep(1);
	}
	sigemptyset(&old); // empty another set ignore the name
	sigaddset(&old, SIGQUIT); // add sigwuit to it
	if(sigprocmask(SIG_UNBLOCK, &old, NULL) < 0) // tell the system to unblock based on the new set named old
		printf("FAILING@");//change mask
	for(i = 1; i<6; i++){ // now print 0-5 with cntrl c unblocked but handled, and cntrl \ still blocked meaning it does nothing
		printf("%d\n", i);
		sleep(1);
	}
	exit(0);
}
