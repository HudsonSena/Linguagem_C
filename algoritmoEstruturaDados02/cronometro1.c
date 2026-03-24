#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
long long memo[MAX_N];
int calculado[MAX_N];

long long fibonacci(int n) {
    if(n<=1) {
        return n;
    }
    if(calculado[n]) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    calculado[n] = 1;
    return memo[n];
}

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    long long res;
    
    int x = 0, n = atoi(argv[1]);
    start = clock();
    res = fibonacci(n);
    end = clock();
    cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
    printf("Fibonacci(%d): %d\n", n, res);
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
}