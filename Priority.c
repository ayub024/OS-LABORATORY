#include <stdio.h>

int main() {
    int i, j, n, wt[10], tat[10], bt[10], pr[10], temp,p[10];
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("\nEnter the burst time and priority of each Process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &pr[i]);
        p[i]=i;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }
    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }
    printf("\nProcess\tBurstTime\tPriority\tWaitingTime\tTurnaroundTime\n\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    return 0;
}
