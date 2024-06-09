#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to perform the knapsack algorithm using dynamic programming
void knapSack(int n, int *weights, int *values, int capacity) {
    int i, w;
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }

    // Build table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int res = dp[n][capacity];
    printf("Total value = %d\n", res);

    w = capacity;
    for (i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
            printf("Item %d: value %d, weight %d\n", i, values[i - 1], weights[i - 1]);
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *weights = (int *)malloc(n * sizeof(int));
    int *values = (int *)malloc(n * sizeof(int));

    printf("Enter the weights and values respectively...\n");
    for (int i = 0; i < n; i++) {
        printf("Weight %d: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Values %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    knapSack(n, weights, values, capacity);

    free(weights);
    free(values);
    return 0;
}
