#include<stdio.h>

void main() {
    int i,j,n,times,remain,flag=0,ts;
    int bt[10],at[10],rt[10];
    int sum_wait=0,sum_tat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++) {
        printf("Enter arrival time and burst time for process P%d:\n",i+1);
        scanf("%d",&at[i]);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter time slice: ");
    scanf("%d",&ts);
    for(times=0,i=0;remain!=0;) {
        if(rt[i]<=ts && rt[i]>0) {
            times += rt[i];
            rt[i]=0;
            flag=1;
        }
        else if(rt[i]>0) {
            rt[i] -= ts;
            times += ts;
        }
        if(rt[i]==0 && flag==1) {
            remain--;   //process completed
            sum_wait += times-at[i]-bt[i];
            sum_tat += times-at[i];
            flag=0;
        }
        
        if(i==n-1) {
            i=0;
        }
        else if(at[i+1]<=times) {
            i++;
        }
        else {
            i=0;
        }
    }
    printf("\nTotal waiting time = %d",sum_wait);
    printf("\nAverage waiting time = %f",(float)sum_wait/(float)n);
    printf("\nTotal turn around time = %d",sum_tat);
    printf("\nAverage turn around time = %f",(float)sum_tat/(float)n);
}
