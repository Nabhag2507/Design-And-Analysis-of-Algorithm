#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* merge(int left[], int right[], int leftLength, int rightLength){
    int *ans = (int *)malloc((leftLength + rightLength) * sizeof(int));
    int i = 0, j = 0, k = 0;
    while(i < leftLength && j < rightLength){
        if(left[i] < right[j]){
            ans[k++] = left[i];
            i++;
        } else {
            ans[k++] = right[j];
            j++;
        }
    }
    while(i < leftLength){
        ans[k++] = left[i];
        i++;
    }
    while(j < rightLength){
        ans[k++] = right[j];
        j++;
    }
    return ans;
}

int* merge_sort(int arr[], int s, int e){
    if(s == e){
        int *newArr = malloc(sizeof(int));
        newArr[0] = arr[s];
        return newArr;
    }

    int mid = s + (e - s) / 2;

    int *left = merge_sort(arr, s, mid);
    int *right = merge_sort(arr, mid + 1, e);

    int *ans = merge(left, right, mid - s + 1, e - mid);

    free(left);
    free(right);

    return ans;
}

int main () {
    clock_t start, end;
    double time_taken;

    start = clock();

    int arr[] = {12, 52, 2, 86, 20, 23, 55, 10, 9, 36};

    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    int *sorted = merge_sort(arr, 0, 9);

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%d ", sorted[i]);
    }

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %.2lf ms", time_taken);
}