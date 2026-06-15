#include <stdio.h>
#include <time.h>

int sum(int n){
    if(n == 0){
        return 0;
    }
    return n + sum(n - 1);
}

void main () {
    clock_t start, end, time_taken;
    start = clock();
    printf("%d ", sum(5));
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}