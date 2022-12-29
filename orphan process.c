#include<stdio.h>
#include<unistd.h>
int main ()
{
    printf("orphan Process\n");
    int x=fork();
    if(x==0)
    {
        printf("child\n");
        sleep(1);
        printf("child process id: %d\n",getpid());
        printf("child process show parent id: %d\n",getpid());
    }
    else
    {
        printf("parent\n");
        printf("parent process id: %d\n",getpid());
    }
}
