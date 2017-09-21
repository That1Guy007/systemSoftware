//this program shows the use of  full duplex pipes ( really just two pipes for input and output)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int data_processed;
    int file_pipes[2], fd[2];
    const char some_data[] = "Hey there kiddo"; //data to be passed to the child
    char buffer[BUFSIZ + 1];
    char buf[BUFSIZ +1];
    char rBuff[256];
    pid_t fork_result;// saves the pid
    memset(buffer, '\0', sizeof(buffer));/ clear the buffer
    if (pipe(file_pipes) ==0 && pipe(fd) == 0) {//need to explicityly define the pipes declared usinf fd's
        fork_result = fork(); // creates the child
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }
        if (fork_result == 0) {
            close(file_pipes[1]); // closes the write end of the pipe that the child is expecting input from
            close(fd[0]);//closes the read end of the pipe that the child expects to write data through
            sprintf(buffer, "%d", file_pipes[0]); //saves the filde descriptors f the pipe and passes them the the program called in the execl function
            sprintf(buf, "%d", fd[1]);// this is the write end of the pipe the child will use to send data to the parent
            if(execl("twoPipeschild", "twoPipeschild", buffer, buf, (char *)0) < 1) //executes another program which will utilize the pipes by reading the data and sending some data
                printf("FAILING EXEC");
            exit(EXIT_FAILURE);
        }
        else {
            close(file_pipes[0]); // close the read end of the pipe the parent will send data through
            close(fd[1]); //close the write end of the pipe the parent will be reading data from
            data_processed = write(file_pipes[1], some_data, strlen(some_data)); // write the data
            printf("%d -Parent wrote %d bytes\n", getpid(), data_processed);// print the amount of data sent
            //wait();
            int Data = read(fd[0], rBuff, sizeof(rBuff));//read the data the child sent to the parent
            printf("%d -Parent read %d bytes: %s\n", getpid(), Data, rBuff);
        }
    }
    exit(EXIT_SUCCESS);
}
