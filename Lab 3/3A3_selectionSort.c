#include <stdio.h>
#include <time.h>

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int size = 7;
    int arr[] = {1, 19, 4, 31, 38, 25, 100};

    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}