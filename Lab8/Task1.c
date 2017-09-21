//this program uses threads to calculate the sum and the factorial of a passed argument
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *sum(void* n){
	int num = (int)n;
	int sum =0;
	for (int i = 1; i <= num; i++){
		sum= sum + i;
	}
	printf("The sum from 0 to %d is : %d\n", num, sum);
	pthread_exit(NULL);
}

void* factorial(void* N){
	int num = (int)N;
	int final = 1;
	for (int i =1; i<= num; i++){
		final = final * i;
	}
	printf("The factorial from 1 to %d is: %d\n", num, final);
	pthread_exit(NULL);
}

//pass in agruments if segfaults

void main(int argc, char** argv){
    if(argc <2){
        printf("No arguments passed");
        exit(1);
    }
	pthread_t threads[2];
	int i;
	for(i = 1; i< 3; i++){
		printf("In main: creating %d\n", i);
		if(i==1)
			pthread_create(&threads[i-1], NULL,sum,(void* )atoi(argv[i]));
		if(i==2)
			pthread_create(&threads[i-1],NULL, factorial, (void*) atoi(argv[i]));
	}
	pthread_exit(NULL);
	exit(0);
}
