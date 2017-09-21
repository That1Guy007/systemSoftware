//program is supposed to read data and pass the data to a child using a pipe then the child sums the data and the parent again does its thing.. doesnt work
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX 256

int main(){
    int fd[2];
    pid_t pid;
    if(pipe(fd) < 0)
        printf("PIPE ERROR");
    pid = fork();
    char num[MAX], num2[MAX];
    if(pid >0){
        close(fd[0]);
        while(fgets(num, MAX,stdin) != NULL){//fgets?
            write(fd[1],&num, strlen(num));
        }
    }
    else{
        int sum;
        close(fd[1]);
       //if(execl("~/Documents/350/Lab8/cSum.c", "cSum",(char* ) NULL))//, fd[0],(char *) NULL) <0)
        //printf("EXEC FAIL");
        char data[MAX], data2[MAX];
        int num, num2;
        while(read(fd[0],&data, sizeof(data))){
            sscanf(data, "%d%d", &num, &num2);///parse thruogh data grab ints
        //    if(data == EOF)//cntrl-D
      //          exit(0);
    //        if(isdigit(num) == -1 || isdigit(num2) == -1){
  //              pritnf("NUM error");
//                exit(1);
            //}
            sum = num + num2;
          // sleep(2);
            printf("%d is the sum of %d and %d", sum, num, num2);
        }
    }
    exit(0);
}
