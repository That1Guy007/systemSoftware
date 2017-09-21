//this program uses threads to poopulate an array then uses that array to make calulation and observations then deletes all of its data
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 20
int array[20];

void BubbleSort(){ // bubble sort is used to organize the array and determine the medium value
	int Bool = 1, j = 0, tmp;
	while(Bool){
		Bool = 0;
		j++;
		for(int i =0; i<SIZE -j;i++){
			if(array[i+1] == NULL)
				break;
			if(array[i] > array[i+1]){
				tmp = array[i];
				array[i] = array[i+1];
				array[i +1] = tmp;
				Bool =1;
			}
		}
	}
}

void* getData(){ //first threads function which populates the array
	int iData;
	int i = -1;
	printf("Please input data of test scores, if done inputing data please type -1\n");
	while(scanf("%d", &iData) == 1 && i++ != 20){
		if(iData == -1)
			break;
		array[i] = iData;
		//printf("%d", array[i]);
	}
	pthread_exit(NULL);//each thread needs to exit with this command
}

void* calc(){ //calculates the medium and avg value of the array
	printf("Thread 2 is calculating based on array variables\n");
	int sum= 0;
	int i = 0;
	BubbleSort();
	for(i; i < SIZE; i++){
		if(array[i] == NULL){
			printf("Done with array, no more data\n");
			break;
		}
		sum = sum + array[i];
	}
	int avg;
	if(i == 0)
		avg =0;
	else
		avg = sum /i;
	printf("The average value of test scores is: %d. The medium value is : %d\n" , avg, array[i/2]);
	pthread_exit(NULL);
}

void* minMax(){ // finds the min and max of the array
	int i =0;
	int min = 100, max = 0;
	for(i; i<SIZE; i++){
		if(array[i] == NULL)
			break;
		if(array[i] >max)
			max = array[i];
		if(array[i] < min)
			min = array[i];
	}
	printf("The min value is %d, the max value is %d\n",min, max);
	pthread_exit(NULL);
}

void* clear(){ // the 4th thread uses this to clear the array
	for(int i = 0;i<SIZE; i++){
		array[i] = 0;
		printf("%d\n", array[i]);
	}

}

void main(){
	int num;
	scanf("%d", &num); // input the number of threads you want but should be 4 in this case
	pthread_t threads[num]; // prepare the specified number of threads
	//void *idk;
	int i=0;
	for(i; i<4; i++){//for loop creates threads and calls the seperate functions
		if(i == 0)
			pthread_create(&threads[i],NULL, getData,NULL); // creates thread 1 and calls the getdata function passes nothing in
		else if( i == 1){
			pthread_create(&threads[i], NULL, calc, NULL);
//			pthread_join(threads[i-1], NULL);
			}
		else if(i == 2)
			pthread_create(&threads[i], NULL, minMax, NULL);
		else if (i == 3)
			pthread_create(&threads[i],NULL,clear, NULL);
                pthread_join(threads[i], NULL);//join each function in order to be sure that none of the threads influeance the others inappropraitely

	}
	pthread_exit(NULL);//exit each thread
	exit(0);
}
