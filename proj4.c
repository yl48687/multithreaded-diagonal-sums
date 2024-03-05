#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "proj4.h"

void initializeGrid(grid * g, char * fileName) {
    FILE * file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    } // if

    unsigned int n = 0;

    while (fgetc(file) != '\n') {
        n++;
    } // while

    rewind(file);

    g -> n = n;
    g -> p = (unsigned char **) malloc(n * sizeof(unsigned char *));

    for (unsigned int i = 0; i < n; i++) {
        g -> p[i] = (unsigned char *) malloc(n * sizeof(unsigned char));

        for (unsigned int j = 0; j < n; j++) {
            fscanf(file, "%1hhu", &(g -> p[i][j]));
        } // for
    } // for

    fclose(file);
} // initialize

void * computeDiagonalSums(void * arg) {
    return arg;
} // computeDiagonalSums

void diagonalSums(grid * input, unsigned long s, grid * output, int t) {
    output -> n = input -> n;
    output -> p = (unsigned char **) malloc(output -> n * sizeof(unsigned char *));

    for (unsigned int i = 0; i < output -> n; i++) {
        output -> p[i] = (unsigned char *) calloc(output -> n, sizeof(unsigned char));
    } // for

    pthread_t threads[t - 1];
    for (int i = 0; i < t - 1; i++) {
        pthread_create(&threads[i], NULL, computeDiagonalSums, NULL);
    } // for

    for (int i = 0; i < t - 1; i++) {
        pthread_join(threads[i], NULL);
    } // for
} // diagonalSums

void writeGrid(grid * g, char * fileName) {
    FILE * file = fopen(fileName, "w");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    } // if

    for (unsigned int i = 0; i < g -> n; i++) {
        for (unsigned int j = 0; j < g -> n; j++) {
            fprintf(file, "%hhu", g -> p[i][j]);
        } // for
        fprintf(file, "\n");
    } // for

    fclose(file);
} // writeGrid

void freeGrid(grid * g) {
    for (unsigned int i = 0; i < g -> n; i++) {
        free(g -> p[i]);
    } // for

    free(g -> p);
} // freeGrid
