#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#define SIZE 4096
void syscall_copy(char *src,char *dest)
{
    int fd1,fd2,n;
    char buffer[SIZE];
    fd1=open(src,O_RDONLY);
    fd2=open(dest,O_WRONLY|O_CREAT|O_TRUNC,0644);
    while((n=read(fd1,buffer,SIZE))>0)
        write(fd2,buffer,n);
    close(fd1);
    close(fd2);
}
void library_copy(char *src,char *dest)
{
    FILE *fp1,*fp2;
    char buffer[SIZE];
    int n;
    fp1=fopen(src,"r");
    fp2=fopen(dest,"w");
    while((n=fread(buffer,1,SIZE,fp1))>0)
        fwrite(buffer,1,n,fp2);
    fclose(fp1);
    fclose(fp2);
}
int main()
{
    clock_t start,end;
    start=clock();
    syscall_copy("input.txt","syscall.txt");
    end=clock();
    printf("System call time:%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    start=clock();
    library_copy("input.txt","library.txt");
    end=clock();
    printf("Library time:%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
