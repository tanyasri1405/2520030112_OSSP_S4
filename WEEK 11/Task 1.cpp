#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
int main()
{
    int fd;
    char *ptr;
    fd=open("file.txt",O_RDWR);
    if(fd<0)
    {
        perror("open");
        exit(1);
    }
    ptr=mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr==MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }
    printf("%s\n",ptr);
    ptr[0]='A';
    munmap(ptr,100);
    close(fd);
    return 0;
}
