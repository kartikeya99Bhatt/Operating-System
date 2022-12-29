#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
struct process
{
    int allocate[100],max[100],need[100];
};
int main ()
{
    int n;
    printf("Enter  the  number of process: ");
    scanf("%d",&n);
    struct process p[n];
    
    int r;
    printf("Enter the number of resource: ");
    scanf("%d",&r);
    
    int avg[r];
    printf("Enter the resource instance: ");
    for(int i=0;i<r;i++){
        scanf("%d",&avg[i]);
    }
 
    
    for(int i=0;i<n;i++)
    {
        printf("Enter the max need of process ");
        for(int j=0;j<r;j++)
        {
            scanf("%d",&p[i].max[j]);
        }
        
        for(int j=0;j<r;j++)
        {
            scanf("%d",&p[i].allocate[j]);
            p[i].need[j]=p[i].max[j]-p[i].allocate[j];
            avg[j]-=p[i].allocate[j];
        }
    }
    
    // printing
    printf("\n allocate");
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<r;j++){
           printf("%d ",p[i].allocate[j]);
       } 
      printf("\n");
    }
    
     printf("\n max");
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<r;j++){
           printf("%d ",p[i].max[j]);
       } 
       printf("\n");
    }
    
     printf("\n need");
     for(int i=0;i<n;i++)
    {
       for(int j=0;j<r;j++){
           printf("%d ",p[i].need[j]);
       } 
       printf("\n");
    }
    
    printf("The resource available : ");
    for(int i=0;i<r;i++){
        printf("%d ",avg[i]);
    }
    
    // logic
    
    int sq=0;
    bool visited[n];
    int count=0;
    
    printf("The sequence is safe\n");
    printf("The sequence is ");
    while(true)
    {
        int sq=0;
        for(int i=0;i<n;i++)
        {
            
            int j=0;
            if(visited[i]==true)
            {
                continue;
            }
            for(j=0;j<r;j++)
            {
                if(avg[j]<p[i].need[j])
                {
                    break;
                }
            }
            if(j==r)
            {
                sq=i;
                break;
            }
            
        }
        for(int k=0;k<r;k++){
            avg[k]+=p[sq].allocate[k];
        }
        visited[sq]=true;
        printf("%d ",sq+1);
        count++;
        if(count==n)
        {
            break;
        }
    }   
    
   
    return 0;
}


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Process{
    int allocation[100],max[100],need[100];
};

int main(){
    int n,r;
    
    
    printf("Enter no. of Processes: ");
    scanf("%d",&n);
    struct Process p[n];
    bool freq[n];
    printf("Enter no. of resoures: ");
    scanf("%d",&r);

    int avg[r];
    printf("Enter no. of instances of resource: ");
    for(int i=0;i<r;i++){
        scanf("%d",&avg[i]);
    }
    
    for(int i=0;i<n;i++){
        printf("Enter the max need of process: ");
        for(int j=0;j<r;j++){
            scanf("%d",&p[i].max[j]);
        }

        printf("Enter the allocation of process: ");
        for(int j=0;j<r;j++){
            scanf("%d",&p[i].allocation[j]);
            p[i].need[j]=p[i].max[j]-p[i].allocation[j];
            avg[j]-=p[i].allocation[j];
        }
        freq[i]=false;
    }

    int n1=0;
    bool flag=true;
    int sq[n];
    int sqi=0;
    while(n1<n){
        int i=0,j=0;
        for(i=0;i<n;i++){
            if(freq[i]==true){
                continue;
            }
            for(j=0;j<r;j++){
                if(avg[j]<p[i].need[j]){
                    break;
                }
            }
            if(j==r){
                freq[i]=true;
                break;
            }
        }
        if(i==n){
            flag=false;
            break;
        }
        n1++;
        for(int k=0;k<r;k++){
            avg[k]+=p[i].allocation[k];
        }
        sq[sqi++]=i+1;
    }


    if(flag){
        printf("\nSafe squence!\n");
        printf("Sequence is: ");
        for(int i=0;i<n;i++){
            printf("%d ",sq[i]);
        }
    }
    else{
        printf("Not a safe sequence!");
    }

    return 0;
}
