#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int maxrange;
    printf("\nEnter the maximum range: ");
    scanf("%d",&maxrange);
    int n;
    printf("\nEnter the no of request: ");
    scanf("%d",&n);
    int head;
    printf("\nEnter the value of head: ");
    scanf("%d",&head);
    
    printf("\nEnter the disk value: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    // sorting ->selection sort 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
          if(arr[i]>arr[j])
          {
             int temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
          }   
        }
    }
    // printf
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    // logic
    int d;
    printf("Enter the choice if want to: 1 left , 2 right\n");
    scanf("%d",&d);
    
    // finding the head position 
    int hidx=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>head)
        {
            hidx=i;
            break;
        }
    }
    
    int tst=0;
    
    if(d==1)// left movement 
    {
        for(int i=hidx-1;i>=0;i--)
        {
         tst+=abs(head-arr[i]);
          head=arr[i]; 
       }
       tst+=abs(head-0);
       head=0;
       for(int i=hidx;i<n;i++)
      {
          tst+=abs(head-arr[i]);
          head=arr[i];
      }
    }
    else if(d==2)// right movement 
    {
      for(int i=hidx;i<n;i++)
      {
          tst+=abs(head-arr[i]);
          head=arr[i];
      }
      tst+=abs(head-199);
      head=maxrange;
      for(int i=hidx-1;i>=0;i--)
      {
         tst+=abs(head-arr[i]);
          head=arr[i]; 
      }
    }
    printf("\n The Total SeekTime is : %d ",tst);
}
