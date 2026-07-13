#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int len, int target){
    int left = 0;
    int right = len - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
    
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {10, 20, 30, 40, 50, 60};

    int ansFirst = binarySearch(arr1, 5, 30);
    int ansSecond = binarySearch(arr2, 6, 20);

    printf("%d %d", ansFirst, ansSecond);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}