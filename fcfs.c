#include<stdio.h>
#include <stdio.h>

int main() {
    int i, n, wt[10], tat[10], bt[10];
    float awt = 0, wtat = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst time of each Process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        wtat += tat[i];
    }

    printf("\nProcess\tBurstTime\tWaitingTime\tTurnaroundTime\n\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time of Processes: %.2f\n", awt / n);
    printf("Average Turnaround Time of Processes: %.2f\n", wtat / n);

    return 0;
}
