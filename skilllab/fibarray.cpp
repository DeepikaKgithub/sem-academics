#include <stdio.h>

int fibBottomUp(int n) {
    int fibArray[n + 1];
    fibArray[0] = 0;
    fibArray[1] = 1;

    for (int i = 2; i <= n; i++)
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];

    return fibArray[n];
}

int main() {
    int n = 8;
    printf("Fibonacci(%d) using bottom-up approach = %d\n", n, fibBottomUp(n));

    return 0;
}
