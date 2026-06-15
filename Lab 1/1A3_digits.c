#include <stdio.h>
#include <time.h>

int digits(int n){
    if(n <= 9){
        return 1;
    }
    return 1 + digits(n / 10);
}

void main () {
    clock_t start, end, time_taken;
    start = clock();
        
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}