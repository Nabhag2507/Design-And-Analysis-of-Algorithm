#include <stdio.h>
#include <time.h>

int fibonacci(int n){
    if(n < 2) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int n = 8;
    for(int i = 0; i < n; i++){
        printf("%d ", fibonacci(i));
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}