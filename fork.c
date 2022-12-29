#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
    printf("process id: %d \n",getpid());
}
