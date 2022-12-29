#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
bool find(int b[],int val,int s)
{
     for(int i=0;i<s;i++){
        if(b[i]==val)
            return true;
    }
    return false;
}
void print(int b[],int s){
    for(int i=0;i<s;i++){
        printf("%d\t",b[i]);
    }
    printf("\n");
}
int main ()
{
    int n;int s;
    printf("Enter the number of pages and framesize: ");
    scanf("%d%d",&n,&s);
    
    int a[n];int b[s];
    for(int i=0;i<n;i++){
        printf("\nEnter the page value : ");
        scanf("%d",&a[i]);
    }
    for(int i=0;i<s;i++){
        b[i]=-1;
    }
    int cntpf=0;
    int ridx=0;
    for(int i=0;i<n;i++)
    {
        int ele=a[i];
        if(find(b,ele,s)==false)
        {
            int idx=ridx%s;
            b[idx]=ele;
            ridx++;
            cntpf++;
        }
        print(b,s);
    }
    printf("\nThe total number of page fault is : %d ",cntpf);
}
