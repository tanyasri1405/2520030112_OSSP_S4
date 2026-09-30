#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
int main(int argc,char *argv[])
{
    int source,destination;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead,bytesWritten;
    if(argc!=3)
    {
        printf("Usage: %s <source_file> <destination_file>\n",argv[0]);
        return 1;
    }
    source=open(argv[1],O_RDONLY);
    if(source<0)
    {
        perror("Source file open error");
        return 1;
    }
    destination=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(destination<0)
    {
        perror("Destination file open error");
        close(source);
        return 1;
    }
    while((bytesRead=read(source,buffer,BUFFER_SIZE))>0)
    {
        bytesWritten=write(destination,buffer,bytesRead);
        if(bytesWritten!=bytesRead)
        {
            perror("Write error");
            break;
        }
    }
    lseek(source,0,SEEK_SET);
    close(source);
    close(destination);
    printf("File copied successfully\n");
    return 0;
}
