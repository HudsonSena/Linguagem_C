#include <stdio.h>
#include <stdlib.h>
int fib(int a) {
    int auxA, auxB;
    if(a<2) {
        return a;
    } else {
        auxA = fib(a-1);
        auxB = fib(a-2);
        return auxA + auxB;
    }
}
void main(int argc, char *argv[]) {
    long long int x = atoi(argv[1]);
    //int y = atoi(argv[2]);
    printf("Fibonacci: %lld\n", fib(x));
    //print("Fibonacci: %d\n", fib(y));
}