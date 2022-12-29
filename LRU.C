#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool find (int b[],int ele,int s){
    for(int i=0;i<s;i++){
        if(b[i]==ele)
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
int index(int frame[],int ele,int s)
{
    for(int i=0;i<s;i++){
        if(frame[i]==ele)
        {
            return i;
        }
    }
    return 100;
}
int main(){

    int n,s;
    printf("\nEnter no. of pages: ");
    scanf("%d",&n);

    int a[n];
    printf("\nEnter the page numbers: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\nEnter the frame size: ");
    scanf("%d",&s);

    int frame[s];
    for(int i=0;i<s;i++){
        frame[i]=-1;
    }

   // logic for lru
   int cntpf=0;
   int rpidx=0;
   for(int i=0;i<n;i++){
       int ele=a[i];
       if(find(frame,ele,s)==false)
       {
           if(rpidx<s)
           {
             frame[rpidx]=ele;
             cntpf++;   
             rpidx++;
           }
           else
           {
                   int count=0;
                   int vis[s];
                   for(int i=0;i<s;i++){
                       vis[i]=0;
                   }
                 for(int j=i-1;j>=0;j--)
                 {
                     int pe=a[j];
                     if(find(frame,pe,s)==true && vis[index(frame,pe,s)]==0)
                     {
                         vis[index(frame,pe,s)]=1;
                         count++;
                         if(count==s){
                             frame[index(frame,pe,s)]=ele;
                             cntpf++;
                             break;
                         }
                     }
                 }
           }
       }
       print(frame,s);
   }
   printf("\nThe number of pagefault : %d",cntpf);
   
}
//5 6 5 4 1 6 10 4 12 0 1 20
