#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int fib(int);

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    int res, x = 0, n = atoi(argv[1]);
    start = clock();
    res = fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start))/ CLOCKS_PER_SEC;
    printf("Fibonacci(%d): %d\n", n, res);
    printf("Tempo de execucao: %f segundos\n", cpu_time_used);
}

int fib(int n) {
    if(n<2) {
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}