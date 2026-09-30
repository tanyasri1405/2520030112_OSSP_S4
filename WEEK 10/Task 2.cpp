#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
    struct stat file;
    if(argc!=2)
    {
        printf("Usage:%s filename\n",argv[0]);
        return 1;
    }
    stat(argv[1],&file);
    printf("Inode:%ld\n",file.st_ino);
    printf("Size:%ld\n",file.st_size);
    printf("Permissions:%o\n",file.st_mode);
    return 0;
}
