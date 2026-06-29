#include <stdio.h>
#include <time.h>

void main () {
    clock_t start, end, time_taken;
    start = clock();

    // int size = 6;
    // int arr[] = {1, 5, 3, 19, 18, 25};

    // int size = 4;
    // int arr[] = {30, 5, 20, 9};

    int size = 7;
    int arr[] = {1, 19, 4, 31, 38, 25, 100};

    for(int i = 1; i < size; i++){
        for(int j = i; j < size; j++){
            if(arr[j - 1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}