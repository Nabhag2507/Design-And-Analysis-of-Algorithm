#include <stdio.h>
#include <time.h>

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int size = 7;
    int arr[] = {1, 19, 4, 31, 38, 25, 100};

    

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}