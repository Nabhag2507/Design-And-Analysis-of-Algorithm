#include <stdio.h>
#include <time.h>

void main () {
    clock_t start, end, time_taken;
    start = clock();

    // int size = 5;
    // int arr[][2] = {{2, 4}, {1, 2}, {7, 8}, {5, 6}, {6, 8}};

    int size = 3;
    int arr[][2] = {{1, 4}, {10, 15}, {7, 10}};

    // sorting
    for(int i = 1; i < size; i++){
        for(int j = i; j < size; j++){
            if(arr[j - 1][0] > arr[j][0]){
                int temp0 = arr[j][0];
                arr[j][0] = arr[j - 1][0];
                arr[j - 1][0] = temp0;

                int temp1 = arr[j][1];
                arr[j][1] = arr[j - 1][1];
                arr[j - 1][1] = temp1;
            }
        }
    }

    for(int i = 1; i < size; i++){
        if(arr[i - 1][1] > arr[i][0]){
            printf("False.");
            return;
        }
    }
    printf("True.");

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}