#include<stdio.h>

void main() {
    int i,n,j,p[10],bt[10],compt[10],wt[10],tat[10];
    int temp1,temp2;
    float sumwt=0.0,sumtat=0.0;
    printf("Enter no of processes: ");
    scanf("%d",&n);
    printf("Enter the burst time of %d processes: \n",n);
    for(i=0;i<n;i++) {
        scanf("%d",&bt[i]);
    }
    printf("Enter the priority of %d processes: \n",n);
    for(i=0;i<n;i++) {
        scanf("%d",&p[i]);
    }
    
    /*sorting according to priority time*/
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(p[i]>p[j]) {
                temp1=bt[i];
                bt[i]=bt[j];
                bt[j]=temp1;
                temp2=p[i];
                p[i]=p[j];
                p[j]=temp2;
            }
        }
    }
    
    compt[0]=bt[0];
    wt[0]=0;
    for(i=1;i<n;i++) {
        compt[i] = bt[i] + compt[i-1];
    }
    for(i=0;i<n;i++) {
        tat[i] = compt[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }
    
    printf("Total waiting time: %f\n",sumwt);
    printf("Average waiting time: %f\n",sumwt/n);
    printf("Total turn around time: %f\n",sumtat);
    printf("Average turn around time: %f\n",sumtat/n);
}
