#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
#include "diagonal_sums.h"

/*
 * Helper function for main. 
 * Checks for some errors and print error messages for command line arguments
 * passed to main. If an error is found, the program terminates.
 */
void errorCheck(int argc, char ** argv){
  bool errorFound = false;
  if(argc != 5){
    printf("Usage error: ./proj4.out inputFile outputFile s t\n");
    errorFound = true;
  } else if( access(argv[1], F_OK) != 0 ){
    printf("Error accessing %s in the present working directory\n", argv[1]);
    errorFound = true;
  } else {
    int t = atoi(argv[4]);
    if(t < 1 || 3 < t){
      printf("Error: t must be between 1 and 3 (inclusive)\n");
      errorFound = true;
    } // if
  } // if
  if(errorFound) exit(0);
} // if

/*
 * Processes five command line arguments: ./digonal_sums.out input.txt output.txt s t
 *   input.txt    the name of a file in the present working directory that contains
 *                a n-by-n grid of digits (1 through 9), where n >= 1.
 *   output.txt   the name of a file in the present working directory to save the
 *                output of diagonal sums. If the file does not exist, then this file
 *                will be created in the present working directory.
 *   s            the sum for the diagonal sums.
 *   t            the number of threads (1 <= t <= 3) to use to compute the diagonal
 *                sums. If t is 1, then only the main thread will be used. If 2 <= t <= 3,
 *                then the main thread and (t - 1) POSIX thread(s) will be used to compute
 *                the diagonal sums.
 * This program will only time the call to diagonalSums.
 */
int main(int argc, char ** argv){
  errorCheck(argc, argv);
  char * inputFile = argv[1];
  char * outputFile = argv[2];
  unsigned long sum = (unsigned long) atol(argv[3]);
  int t = atoi(argv[4]);
  grid g, diagonalSumsOutput;
  initializeGrid(&g, inputFile);

  printf("Computing the diagonal sums equal to %ld in a %d-by-%d grid using %d thread(s).\n",
         sum, g.n, g.n, t);
  struct timeval start, end;    // start and end time
  unsigned long e_usec; // elapsed microseconds
  gettimeofday(&start, 0); // mark the start time
  diagonalSums(&g, sum, &diagonalSumsOutput, t);
  gettimeofday(&end, 0);        // mark the end time
  e_usec = ((end.tv_sec * 1000000) + end.tv_usec) -
    ((start.tv_sec * 1000000) + start.tv_usec);
  printf("Elapsed time for computing the diagonal sums using %d thread(s): %lf seconds.\n",
         t, e_usec / 1000000.0);

  printf("Writing the diagonal sums equal to %ld to the file %s.\n",
         sum, outputFile);
  writeGrid(&diagonalSumsOutput, outputFile);
  freeGrid(&g);
  freeGrid(&diagonalSumsOutput);
  printf("Program is complete. Goodbye!\n");
  return 0;
} // main