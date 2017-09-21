//this program executes any bash cmd by passing it on using popen() then prints out the result
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
    char buff[256], line[256];
    FILE *ptr;//file pointer
    strcpy(line, argv[1]);// these concates the command into one single command
    strcat(line, " ");
    strcat(line, argv[2]);
    //while(fgets(line, 256, stdin) >0 && line != EOF){
        if((ptr = popen(line, "r")) != NULL){//passed thecommand to the bash and saves returned data
           while( fgets(buff,256, ptr) != NULL){ //this reads what the popen() function returns and then prints it out line by line
                puts(buff);
           }
        }
    //}
}
