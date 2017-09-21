//this program blocks cntrl c once and then resets the handler so that cntrl c stops the program execution
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig){
	struct sigaction act2; // creates a new structure of sigaction
	printf("OUCH! - I got signal %d\n", sig); // print out
	act2.sa_flags = SA_RESETHAND; // uses the flag portion of the structure, in this case reset the structure
	sigaction(SIGINT,&act2,0); // set cntrl c to use the new struct
}

int main(){
	struct sigaction act; // first struct to be used
	act.sa_handler = ouch; // set handler to ouch() function above
	sigemptyset(&act.sa_mask); // clear the mask
	//act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);//set the signal to use the sigaction struct
	while(1) {
		printf("Hello World!\n");// print until cntrl c is hit then use the handler then break out of execution
		sleep(1);
	}
}
