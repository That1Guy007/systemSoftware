//this program uses pipes to pass data though a pipe back to itself
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define READ_END 0 //universal  read end
#define WRITE_END 1 //write end

int main()
{
    int data_processed;
    int file_pipes[2]; //created two ends of the pipe
    const char some_data[] = "123"; //the data to be passed
    char buffer[strlen(some_data)]; // buffer size which will hold the data passed
    memset(buffer, '\0', sizeof(buffer)); //clear buffr
    strcpy(buffer, some_data); // pass sdata into buffer
    if (pipe(file_pipes) == 0) {//create pipe
        //data_processed = read(file_pipes[0], buffer, BUFSIZ);
        data_processed = write(file_pipes[WRITE_END], some_data, strlen(some_data)); //writes the data into the write ende
        printf("Wrote %d bytes\n", data_processed);
        data_processed = read(file_pipes[READ_END], buffer, sizeof(buffer));//reads the data
        //data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("Read %d bytes: %s\n", data_processed, buffer); //print out the data processed
        exit(EXIT_SUCCESS);
        }
    exit(EXIT_FAILURE);
    }
