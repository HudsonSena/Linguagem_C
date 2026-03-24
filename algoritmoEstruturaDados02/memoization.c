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