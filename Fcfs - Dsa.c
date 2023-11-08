#include <stdio.h>

int main() {
    int t[20], n, i, j, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    
    printf("Enter the tracks to be traversed: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &t[i]);

    for (i = 1; i < n; i++) { // Changed the loop condition from n+1 to n
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = -tohm[i];
    }

    for (i = 1; i < n; i++) { // Changed the loop condition from n+1 to n
        tot += tohm[i];
    }

    avhm = (float)tot / n;
    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 1; i < n; i++) { // Changed the loop condition from n+1 to n
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    }
    printf("\nAverage header movements: %f", avhm);
    
    return 0; // Added a return statement to indicate successful program execution
}

