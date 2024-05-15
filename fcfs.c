#include<stdio.h>
#include<stdlib.h>
struct fcfs {
    int pid;
    int btime;
    int wtime;
    int ttime;
}
p[10];

int main() {
    int i,n;
    int totwtime=0, totttime=0;
    printf("FCFS SCHEDULING \n");
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        p[i].pid=i;
        printf("Burst time of the process %d: ",i+1);
        scanf("%d",&p[i].btime);
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    for(i=0;i<n;i++) {
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    printf("\n Total waiting time: %d",totwtime);
    printf("\n Average waiting time: %f",(float)totwtime/(float)n);
    printf("\n Total turn around time: %d",totttime);
    printf("\n Average turn around time: %f",(float)totttime/(float)n);
}
