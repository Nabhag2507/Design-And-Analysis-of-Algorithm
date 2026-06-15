#include <stdio.h>
#include <time.h>

int nearestDivisible(int n, int m){
    int min = 0, max = 0, temp = n;
    while(n % m != 0) n++;
    max = n;

    n = temp;
    while(n % m != 0) n--;
    min = n;
    
    if (temp - min == max - temp) {
        return max > min ? max : min;
    }
    return (temp - min < max - temp) ? min : max;
}

int main(void) {
    clock_t start, end;
    double time_taken_ms;

    start = clock();

    printf("%d ", nearestDivisible(13, 4));

    end = clock();

    time_taken_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("\nTime taken by algorithm : %.3f ms\n", time_taken_ms);

    return 0;
}