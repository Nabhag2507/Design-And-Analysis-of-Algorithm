#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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

    FILE *result = fopen("selection_results.txt", "w");

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

        selectionSort(arr, size);

        clock_t end = clock();

        double time_taken =
            ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

        printf("%s : %.3lf ms\n", files[k], time_taken);

        fprintf(result, "%-20s\t%d\t%.3lf\n",
                files[k], size, time_taken);

        free(arr);
    }

    fclose(result);

    printf("\nResults stored in selection_results.txt\n");

    return 0;
}