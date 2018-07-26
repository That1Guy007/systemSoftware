#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
char buffer[128]; //buffer size 128
int nread = read(0, buffer, 128); //read from 0 which is standard input
if (nread == -1) //if read fails
	write(2, "read Error", 12); //write error to standar error (2)
if((write(1, buffer, nread))!=nread) //as long as write doesnt fail, write to standard out put
	write(2, "write Error", 14); //if failed, write standard error
exit(0);
}
