#include<stdio.h>
void main() {
    int b[20],p[20],i,j,nb,np,best;
    int alloc[20];
    
    printf("Enter no of blocks: ");
    scanf("%d",&nb);
    printf("\nEnter size of each block: \n");
    for(i=0;i<nb;i++) {
        printf("Block no. %d: ",i+1);
        scanf("%d",&b[i]);
    }
    
    printf("\nEnter no of processes: ");
    scanf("%d",&np);
    printf("\nEnter size of each process: \n");
    for(i=0;i<np;i++) {
        printf("Process no. %d: ",i+1);
        scanf("%d",&p[i]);
        alloc[i]=-1;
    }
    
    for(i=0;i<np;i++) {
        best=-1;
        for(j=0;j<nb;j++) {
            if(b[j]>=p[i]) {
                if(best==-1) {
                    best = j;
                }
                else if(b[best]>b[j]) {
                    best=j;
                }
            }
        }
        if(best!=-1) {
            alloc[i]=best;
            b[best] -= p[i];
        }
    }
    
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<np;i++) {
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(alloc[i]!=-1) {
            printf("%d\n",alloc[i]+1);
        }
        else {
            printf("Not allocated\n");
        }
    }
}
