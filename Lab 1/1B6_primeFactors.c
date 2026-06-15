#include <stdio.h>
#include <time.h>

int isPrime(int n){
    for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
            return 0;
        }
        return 1;
    }
}

int primeFactors(int num){
    if(num < 2){
        return 2;
    }
    for(int i = 2; i < num; i++){
        if(isPrime(i) == 1){
            while(num % i == 0){
                printf("%d ", i);
                num /= i;
            }
        }
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int n = 315;
    printf("%d ", primeFactors(n));

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}