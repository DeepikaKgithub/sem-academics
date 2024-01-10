#include<stdio.h>
int fib(int n) {
    if (n <= 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}
int main() {
    int n = 8;
    printf("Fibonacci(%d) using recursion = %d\n", n, fib(n));
    return 0;
}
