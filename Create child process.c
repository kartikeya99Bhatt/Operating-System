#include<stdio.h>
#include<unistd.h>
int main()
{
    int arr[6]={1,0,7,8,90};
    int even=0;int odd=0;;
    int x=fork();
    if(x!=0)
    {
        for(int i=0;i<6;i++){
            if(arr[i]%2==1){
                odd+=arr[i];
            }
        } 
        printf("Process Id: %d , The oddSum is: %d\n",getpid(),odd);
    }
    else
    {
        for(int i=0;i<6;i++){
            if(arr[i]%2==0){
                even+=arr[i];
            }
        }
         printf("Process Id: %d , The evenSum is: %d\n",getpid(),even);
    }
}
