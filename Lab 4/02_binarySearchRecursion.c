#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int len, int target, int left, int right){
    if(right < left){
        return -1;
    }
    int mid = left + (right - left) / 2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[mid] < target){
        return binarySearch(arr, len, target, mid + 1, right);
    }
    return binarySearch(arr, len, target, left, mid - 1);
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {10, 20, 30, 40, 50, 60};

    int ansFirst = binarySearch(arr1, 5, 30, 0, 4);
    int ansSecond = binarySearch(arr2, 6, 20, 0, 5);

    printf("%d %d", ansFirst, ansSecond);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}