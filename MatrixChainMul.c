#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printOptimalParens(int **s, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int matrixChainOrder(int p[], int n) {
    int m[n][n]; // m[i][j] stores the minimum number of multiplications needed to compute the matrix A[i]A[i+1]...A[j]
    int **s = (int **)malloc((size_t)n * sizeof(int *)); // s[i][j] stores the index k at which the optimal split occurs
    for (int i = 0; i < n; i++) {
        s[i] = (int *)malloc((size_t)n * sizeof(int));
    }

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++) { // L is the chain length
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization is: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");

    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);

    return m[1][n - 1];
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int minMultiplications = matrixChainOrder(p, n + 1);
    printf("Minimum number of multiplications is %d\n", minMultiplications);

    return 0;
}