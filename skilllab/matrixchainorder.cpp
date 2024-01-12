#include <stdio.h>
#include <limits.h>

#define N 5

int matrixChainOrder(int p[], int n) {
    int m[N][N];

    // Initialize diagonal elements to 0
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // Build the table in a bottom-up manner
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr[] = {5, 6, 4, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
  printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, size));

    return 0;
}
