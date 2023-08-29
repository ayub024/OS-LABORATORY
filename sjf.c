#include <stdio.h>

int main() {
    int i,j, n, wt[10], tat[10], bt[10],p[10],temp;
    float awt = 0, wtat = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst time of each Process:\n");
    for (i = 1; i <=n; i++) {
        scanf("%d", &bt[i]);
        p[i]=i;
        
    }
    for (i=1;i<=n;i++){
         for (j=i+1;j<=n;j++){
             if (bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
             }
         }
    }
    wt[1] = 0;
    tat[1] = bt[1];

    for (i = 2; i <= n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        wtat += tat[i];
    }

    printf("\nProcess\tBurstTime\tWaitingTime\tTurnaroundTime\n\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time of Processes: %.2f\n", awt / n);
    printf("Average Turnaround Time of Processes: %.2f\n", wtat / n);

    return 0;
}
