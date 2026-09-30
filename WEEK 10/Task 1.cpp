#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int fd;
    fd=open("output.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }
    dup2(fd,STDOUT_FILENO);
    close(fd);
    printf("Output redirected using dup2()\n");
    return 0;
}
