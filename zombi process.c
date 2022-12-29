#include<stdio.h>
#include<unistd.h>
int main ()
{
    printf("Zombi Process\n");
    int x=fork();
    if(x==0)
    {
        printf("child\n");
        printf("child process id: %d\n",getpid());
        printf("child process show parent id: %d\n",getpid());
    }
    else
    {
        printf("parent\n");
        sleep(5);
        printf("parent process id: %d",getpid());
    }
}
