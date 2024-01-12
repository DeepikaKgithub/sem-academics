#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);

    int dp[MAX][MAX];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
char X[] = "ABCDGH";
    char Y[] = "AEDFHR";

    printf("Length of LCS is %d\n", lcs(X, Y));

    return 0;
}
