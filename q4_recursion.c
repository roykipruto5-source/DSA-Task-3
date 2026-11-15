/* Q4: Recursive programs */
#include <stdio.h>

int sumN(int n)        { return n == 0 ? 0 : n + sumN(n - 1); }
long factorial(int n)  { return n <= 1 ? 1 : n * factorial(n - 1); }
int fib(int n)         { return n <= 1 ? n : fib(n - 1) + fib(n - 2); }

void fibSeries(int n) {
    for (int i = 0; i < n; i++) printf("%d ", fib(i));
    printf("\n");
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers = %d\n", n, sumN(n));
    printf("Factorial of %d = %ld\n", n, factorial(n));
    printf("Fibonacci term %d = %d\n", n, fib(n));
    printf("First %d Fibonacci terms: ", n);
    fibSeries(n);
    return 0;
}
