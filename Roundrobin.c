#include <stdio.h>

int main() {
    int i, j, t, n, wt[10], tat[10], ct[10], bt[10], p[10], temp = 0, max = 0;
    float awt = 0, wtat = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst time of each Process:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i;
        ct[i] = bt[i];
    }

    printf("Enter the Time slice: ");
    scanf("%d", &t);

    for (i = 1; i <= n; i++) {
        if (max < bt[i]) {
            max = bt[i];
        }
    }

    for (j = 0; j <= (max / t) + 1; j++) {
        for (i = 1; i <= n; i++) {
            if (bt[i] != 0) {
                if (bt[i] <= t) {
                    tat[i] = temp + bt[i];
                    temp = temp + bt[i];
                    bt[i] = 0;
                } else {
                    bt[i] = bt[i] - t;
                    temp = temp + t;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        wt[i] = tat[i] - ct[i];
        awt += wt[i];
        wtat += tat[i];
    }

    printf("\nProcess\tBurstTime\tWaitingTime\tTurnaroundTime\n\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time of Processes: %.2f\n", awt / n);
    printf("Average Turnaround Time of Processes: %.2f\n", wtat / n);

    return 0;
}
