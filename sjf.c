#include<stdio.h>
#include<stdlib.h>
struct process
{
    int pid,at,bt,ct,tat,wt,st,rt;
};
int main()
{
    printf("Enter the number of process: ");
    int n;
    scanf("%d",&n);
    
    struct process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i;
        printf("\nEnter the  At ,Bt : ");
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    
    // sort on the basic of arrival time (selection sort)
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
          if(p[j].bt<p[i].bt)
          {
            struct process temp=p[i];
            p[i]=p[j];
            p[j]=temp;
          }
        }
    }
    // print
    // working 
    float ideal,ttat,atat,twt,atwt,trt,atrt;
    
   for(int i=0;i<n;i++)
    {
      if(i==0)
      {
          p[i].st=p[i].at;
          p[i].ct=p[i].at+p[i].bt;
          ideal+=p[i].st;
      }
      else if(p[i].at>=p[i-1].ct)
      {
         p[i].st=p[i].at;
         p[i].ct=p[i].at+p[i].bt;
         // ideal
         ideal+=p[i].at-p[i-1].ct;
      }
      else
      {
        p[i].st=p[i-1].ct;
        p[i].ct=p[i].st+p[i].bt;
      }
      p[i].tat=p[i].ct-p[i].at;
      p[i].wt=p[i].tat-p[i].bt;
      p[i].rt=p[i].st-p[i].at;
      
      ttat+=p[i].tat;
      twt+=p[i].wt;
      trt+=p[i].rt;
    }
    atat=ttat/n;
    atwt=twt/n;
    atrt=trt/n;
    
// ---------------------------PRINTING---------------------------------

float cyclelength=p[n-1].ct-p[0].at;
float cpu=((cyclelength-ideal)/cyclelength)*100;
float throughput=n/cyclelength;
     printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }
    
    printf("\n\nTotal Turn Around Time: %.2f",ttat);
    printf("\nAverage Turn Around Time: %.2f",atat);
    printf("\nTotal Waiting Time: %.2f",twt);
    printf("\nTotal Avergae Waiting Time: %.2f",atwt);
    printf("\nTotal Response Time: %.2f",trt);
    printf("\nTotal Avergae Response Time: %.2f",atrt);
    printf("\nCPU Utilization(percent): %.2f",cpu);
    printf("\nIdeal Time: %.2f",ideal);
    printf("\nThroughput Time: %.2f",throughput);
    printf("\nCycle Length: %.2f",cyclelength);
    printf("\nCPU Utilization: %.2f\n\n",cpu);
    
    return 0;
}
