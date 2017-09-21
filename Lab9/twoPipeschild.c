#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    int data_processed;
    const char data [] = "Hi mom";
    char buffer[BUFSIZ + 1];
    int file_descriptor, fd;
    memset(buffer, '\0', sizeof(buffer));
    sscanf(argv[1], "%d", &file_descriptor);
    sscanf(argv[2], "%d", &fd);
  /*  int wData = write(fd, "Hi mom", 6);
    printf("%d - wrote, %d bytes\n", getpid(), wData);*/
    data_processed = read(file_descriptor, buffer, BUFSIZ);
    printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
    int wData = write(fd, data, strlen(data));
    printf("%d - wrote, %d bytes\n", getpid(), wData);
    exit(EXIT_SUCCESS);
}
