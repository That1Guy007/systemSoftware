#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void main(int argc, char ** argv){
	char line[256];
    int sum;
        //close(argv[1]);
    char data[256];
    int num, num2;
    int fd = atoi(argv[1]);
    while(read(fd,&data, sizeof(data)) != -1){
        sscanf(data, "%d%d", &num, &num2);///parse thruogh data grab ints
        if(data == EOF)//cntrl-D
            exit(0);
        //num = atoi(data);
        //num2 = atoi(data2);
        if(isdigit(num) == -1 || isdigit(num2) == -1){
            pritnf("NUM error");
            exit(1);
        }
        sum = num + num2;
        sleep(2);
        printf("%d is the sum of %d and %d", sum, num, num2);
        }
        printf("Working");
        exit(0);
}
