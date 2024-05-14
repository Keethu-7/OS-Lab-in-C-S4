#include<stdio.h>

struct sjf {
    int pid;
    int btime;
    int wtime;
    int ttime;
}
p[10];

void main() {
    int i,n,j;
    struct sjf temp;
    int totwtime=0, totttime=0;
    printf("____SJF SCHEDULING___ \n");
    printf("Enter no of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Enter process id: P");
        scanf("%d",&p[i].pid);
        printf("Enter burst time: ");
        scanf("%d",&p[i].btime);
        printf("\n");
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    
    /*sorting*/
    for(i=0;i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if (p[i].btime>p[j].btime) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++) {
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime +=p[i].wtime;
    }
    
    printf("Total waiting time: %d\n",totwtime);
    printf("Average waiting time: %f\n",(float)totwtime/(float)n);
    printf("Total turn around time: %d\n",totttime);
    printf("Average turn around time: %f\n",(float)totttime/(float)n);
    
}
