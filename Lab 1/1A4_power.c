#include <stdio.h>
#include <time.h>

int power(int base, int pow){
    if(pow == 1){
        return base;
    }
    return (base * power(base, pow - 1));
}

void main () {
    clock_t start, end, time_taken;
    start = clock();
    printf("%d ", power(3, 3));
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}