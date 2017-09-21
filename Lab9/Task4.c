//this program demonstrates FIFO (this one uses full duplex)
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int data_processed, ret_val, fd;
    ret_val = mkfifo("/tmp/task4_fifo", 0666); //creates the fifo
    if(ret_val == -1){
        printf("fifo error");
    }
    fd = open("/tmp/task4_fifo", 2); //opens the fifo for read and write (FULL DUPLEX)
    const char some_data[] = "123";//data to be sent
    char buffer[strlen(some_data)]; // buffer used for reading
    memset(buffer, '\0', sizeof(buffer)); //clear the buffer
    strcpy(buffer, some_data);
        //data_processed = read(file_pipes[0], buffer, BUFSIZ);
        data_processed = write(fd, some_data, strlen(some_data));//write to the FIFO
        printf("Wrote %d bytes\n", data_processed);
        data_processed = read(fd, buffer, sizeof(buffer)); //read from the fifo
        //data_processed = write(file_pipes[1], some_data, strlen(some_data));
        printf("Read %d bytes: %s\n", data_processed, buffer);
    exit(0);
    }
/*
if you want to use standard half duplex fifo you must use a parent and child, have one of the processes open the fifo for write after writing data to the fifo
have the other process open the fifo for reading and accept that data which has been written. use wait probably for the child to write its data.
*/
