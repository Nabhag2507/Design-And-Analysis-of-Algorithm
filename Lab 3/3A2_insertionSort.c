#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {

        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

int main() {

    char *files[] = {
        "test files/best_1000.txt",
        "test files/best_10000.txt",
        "test files/best_100000.txt",

        "test files/average_1000.txt",
        "test files/average_10000.txt",
        "test files/average_100000.txt",

        "test files/worst_1000.txt",
        "test files/worst_10000.txt",
        "test files/worst_100000.txt"
    };

    int sizes[] = {
        1000, 10000, 100000,
        1000, 10000, 100000,
        1000, 10000, 100000
    };

    FILE *result = fopen("insertion_results.txt", "w");

    if (result == NULL) {
        printf("Cannot create results file.\n");
        return 1;
    }

    fprintf(result, "File Name\t\t\t\t\t\tElements\t\tTime (ms)\n");
    fprintf(result, "--------------------------------------------------\n");

    for (int k = 0; k < 9; k++) {

        FILE *fp = fopen(files[k], "r");

        if (fp == NULL) {
            printf("Cannot open %s\n", files[k]);
            continue;
        }

        int size = sizes[k];
        int *arr = (int *)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            fscanf(fp, "%d", &arr[i]);
        }

        fclose(fp);

        clock_t start = clock();

        insertionSort(arr, size);

        clock_t end = clock();

        double time_taken =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

        printf("%s : %.3lf ms\n", files[k], time_taken);

        fprintf(result, "%-20s\t%d\t%.3lf\n",
                files[k], size, time_taken);

        free(arr);
    }

    fclose(result);

    printf("\nResults stored in insertion_results.txt\n");

    return 0;
}