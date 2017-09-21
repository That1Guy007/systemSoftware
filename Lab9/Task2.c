//this one basically shows if u clsoe the pipe then u cant use them?
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Remove wait and close in parent and reset pipe for child to 0and not passed as arg
int main(int argc, char** argv){
    if(argc < 2){
        printf("Error no enough arguments");
        exit(1);
    }
    int data_processed;
    int file_pipes[2];
    int status;
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;
    int num = atoi(argv[1]);
    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if (fork_result == 0) {
            sprintf(buffer, "%d",file_pipes[num]);//sprintf ormats string into the buffer from 3rd arg of format 2nd arg
            (void)execl("pipe4", "pipe4", buffer, (char *)0);
            exit(EXIT_FAILURE);
        }
        else {
            close(file_pipes[1]);//closing the write end of the pipe
            wait(&status);//waiting for the child to finish
            data_processed = write(file_pipes[1], some_data, strlen(some_data));
            printf("%d - wrote %d bytes\n", getpid(), data_processed);
        }
    }
exit(EXIT_SUCCESS);
}
