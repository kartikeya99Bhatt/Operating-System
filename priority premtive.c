#include<stdio.h>
#include<stdlib.h>

struct Process{
    int pid,at,bt,ct,tat,wt,rt,st,pt;
};

void sort(struct Process *p,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].at > p[j].at){
                struct Process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}

int FindPos(struct Process* p,int t,int n,int *rem){
    int mnp=1000,mnpp=-1;
    for(int i=0;i<n;i++){
        if(p[i].at>t){
            break;
        }
        if(rem[i]>0 && mnp>p[i].pt){
            mnp=p[i].pt;
            mnpp=i;
        }
    }

    return mnpp;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct Process p[n];
    printf("Enter the value of AT , BT and priority for each process\n");
    for(int i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pt);
        p[i].pid=i+1;
    }

    sort(p,n);

    int rem[n];

    for(int i=0;i<n;i++){
        rem[i]=p[i].bt;
    }

    int idealTime=0,cycleLength=0,totalTAT=0,totalWT=0,totalRT=0;
    float cpuUti=0,throughPut=0,avgTAT=0,avgWT=0,avgRT=0;
    int np=0;
    int r=0,t=p[0].at,c=0;
    
    r++;
    while(np<n){
        int pos=FindPos(p,t,n,rem);
        if(pos==-1){
            t++;
            idealTime++;
            continue;
        }

        if(rem[pos]==p[pos].bt) p[pos].st=t;
        rem[pos]--;

        if(rem[pos]==0){
            p[pos].ct=t+1;
            p[pos].tat=p[pos].ct-p[pos].at;
            p[pos].wt=p[pos].tat-p[pos].bt;
            p[pos].rt=p[pos].st-p[pos].at;
            np++;
            totalRT+=p[pos].rt;
            totalTAT+=p[pos].tat;
            totalWT+=p[pos].wt;
        }
        t++; 
    }

    cycleLength=t;
    cpuUti=((float)(cycleLength-idealTime)/(float)cycleLength)*100;
    throughPut=(float)n/(float)cycleLength;
    avgTAT=(float)totalTAT/(float)n;
    avgWT=(float)totalWT/(float)n;
    avgRT=(float)totalRT/(float)n;

    printf("PID\tAT\tBT\tPRI\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].pt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }

    printf("\nAverage TAT -- %f\n",avgTAT);
    printf("Average WT -- %f\n",avgWT);
    printf("Average RT -- %f\n",avgRT);
    printf("Cycle Length -- %d\n",cycleLength);
    printf("Ideal Time -- %d\n",idealTime);
    printf("CPU Utilization -- %f\n",cpuUti);
    printf("Through Put -- %f\n",throughPut);
}
