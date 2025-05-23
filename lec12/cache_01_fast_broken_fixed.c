#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_timer.h"

double A[MAX][MAX];
double x[MAX];

// Computes matrix-vector multiplication sequentially
int main(int argc, char** argv) {
    double y[MAX]; 
    int i,j,iter;
    double dummy = 0.0;
    srand(time(NULL));
    /* Initialize A and x with random values, and y to 0s*/
    for (i = 0; i < MAX; i++) {
        x[i] = (double) rand() / RAND_MAX; // Random number between 0 and 1
        y[i] = 0.0;
        for (j = 0; j < MAX; j++)
            A[i][j] = (double) rand() / RAND_MAX; // Random number between 0 and 1
    }

    double total_time = 0.0;
    for(iter = 0; iter < ITER; iter++){
        double start, stop;
        GET_TIME(start);
        for (i = 0; i < MAX; i++)        
            for (j = 0; j < MAX; j++)            
                y[i] += A[i][j]*x[j];
        GET_TIME(stop);
        total_time += stop-start;

        // Do something with the values of y to avoid dead code elimination
        for (i = 0; i < MAX; i++)
            dummy += y[i];        
    }
    printf("Dummy value to avoid dead code elimination: %f\n", dummy);
    printf("Average runtime %f sec\n", total_time/ITER);
}
