#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBest(char filename[], int n){
    FILE *fp = fopen(filename, "w");

    for(int i = 0; i < n; i++){
        fprintf(fp, "%d ", i);
    }
    fclose(fp);
}

void generateAverage(char filename[], int n){
    FILE *fp = fopen(filename, "w");

    for(int i = 0; i < n; i++){
        fprintf(fp, "%d ", rand() % 100000);
    }
    fclose(fp);
}

void generateWorst(char filename[], int n){
    FILE *fp = fopen(filename, "w");

    for(int i = n; i >= 1; i--){
        fprintf(fp, "%d ", i);
    }
    fclose(fp);
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    int sizes[] = {1000, 10000, 100000};
    char filename[50];

    // generate files 
    for(int i = 0; i < 3; i++){
        // best case
        sprintf(filename, "best_%d.txt", sizes[i]);
        generateBest(filename, sizes[i]);

        // average case
        sprintf(filename, "average_%d.txt", sizes[i]);
        generateAverage(filename, sizes[i]);

        // worst case
        sprintf(filename, "worst_%d.txt", sizes[i]);
        generateWorst(filename, sizes[i]);
    }

    printf("All 9 files created.");

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}