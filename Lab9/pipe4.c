#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    int data_processed;
    char buffer[BUFSIZ + 1];
    int file_descriptor, fd2;
    memset(buffer, '\0', sizeof(buffer));
    sscanf(argv[1], "%d", &file_descriptor);
    sscanf(argv[2], "%d", &fd2);
    data_processed = read(file_descriptor, buffer, BUFSIZ);
    printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
    //write with ne fd
    exit(EXIT_SUCCESS);
}
