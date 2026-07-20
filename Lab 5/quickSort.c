#include <stdio.h>
#include <time.h>

void quick_sort(int arr[], int low, int high){
    if(low >= high){
        return;
    }

    int s = low;
    int e = high;
    int mid = s + (e - s) / 2;

    int pivot = arr[mid];

    while(s <= e){
        while(arr[s] < pivot){
            s++;
        }
        while(arr[e] > pivot){
            e--;
        }

        if (s <= e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }

    quick_sort(arr, low, e);
    quick_sort(arr, s, high);
}

int main () {
    clock_t start, end;
    double time_taken;

    start = clock();

    int arr[] = {12, 52, 2, 86, 20, 23, 55, 10, 9, 36};

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    quick_sort(arr, 0, 9);

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %.2lf ms", time_taken);
}