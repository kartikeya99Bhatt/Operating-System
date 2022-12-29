#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the number of request: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int head;
    printf("Enter the intial value of head: ");
    scanf("%d",&head);
    
    int tst=0;
    for(int i=0;i<n;i++)
    {
        tst+=abs(head-arr[i]);
        head=arr[i];
    }
    
    printf("The total seek time is:  %d ",tst);
    return 0;
}
