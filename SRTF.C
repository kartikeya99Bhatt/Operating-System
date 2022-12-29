#include<stdio.h>
#include<stdlib.h>
struct process
{
  int at,bt,tat,ct,wt,rt,st,pid;  
};
int findPos(int *rem,struct process *p,int t,int n)
{
    int minval=10000,minpos=-1;
    for(int i=0;i<n;i++)
    {
        if(rem[i]>0 && minval>rem[i] && p[i].at<=t)
        {
            minval=rem[i];
            minpos=i;
        }
    }
    
    return minpos;
}

int main()
{
    int n;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    struct process p[n];
    
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        p[i].st=-1;
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    // sorting ->selection sorting
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[j].at<p[i].at)
            {
                struct process temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
    int rem[n];
    for(int i=0;i<n;i++)
    {
        rem[i]=p[i].bt;
    }
    int t=0;int com=0;
    float idealtime,totalTAT,totalWT;
    
    while(com<n)
    {
        int pos=findPos(rem,p,t,n);
        if(pos==-1)
        {
            idealtime++;
            t++;
            continue;
        }
        else
        {
            if(p[pos].st==-1)
            {
               p[pos].st=t; 
            }
            rem[pos]--;
        }
        
        if(rem[pos]==0)
        {
            com++;
            p[pos].ct=t+1;
            p[pos].tat=p[pos].ct-p[pos].at;
            p[pos].wt=p[pos].tat-p[pos].bt;
            p[pos].rt=p[pos].st-p[pos].at;
            
            totalTAT+=p[pos].tat;
            totalWT+=p[pos].wt;
        }
        t++;
    }
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tST\tRT\n");
    for(int i=0;i<n;i++){
        printf("p-%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].st,p[i].rt);
    }
    
    float cyclelength=t;
    float cputilization=((float)(cyclelength-idealtime)/(cyclelength))*100;
    float thoughput=n/cyclelength;
    printf("%f\n",cputilization);
     printf("%f\n",thoughput);
    return 0;
}
