#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter the number of disk: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int head;
    printf("Enter the head position: ");
    scanf("%d",&head);
    bool visited[n];
    int count=0;
    int tst=0;
    while(count!=n)
    {
        int max=10000;int maxidx=-1;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false && abs(head-arr[i]) <abs(head-max))
            {
                max=arr[i];
                maxidx=i;
            }
        }
        visited[maxidx]=true;
        tst+=abs(head-arr[maxidx]);
        head=arr[maxidx];
        count++;
    }
    printf("The totalseek time is : %d",tst);
}
