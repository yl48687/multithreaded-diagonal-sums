# Multithreaded Diagonal Sums
The project involves designing and implementing a multithreaded program in a Unix environment. The program aims to find the diagonal sums equal to a specified value in an input text file containing a 2D grid of digits. It utilizes multiple threads to efficiently compute diagonal sums and writes the results to an output file.

## Design Overview
The project utilizes multithreading to optimize the computation of diagonal sums in a 2D grid. It employs POSIX threads for parallel processing, ensuring efficient execution of the diagonal sum algorithm. The design focuses on achieving a worst-case runtime complexity of O(n^3) and worst-case space complexity of O(n^2) for the diagonal sum computation.

## Functionality
`diagonal_sums.c`:
- Implements functions defined in `diagonal_sums.h` based on their comments and examples provided.
- Contains the main logic for computing diagonal sums using multiple threads.

`diagonal_sums.h`:
- Contains function prototypes and necessary definitions for `diagonal_sums.c`.
- Provides an interface for accessing the diagonal sums computation functions.

`main.c`:
- Contains the main function responsible for program execution and interaction with the user.
- Handles command-line arguments parsing and calls appropriate functions for computing diagonal sums.

## File Structure and Content
```
multithreaded-diagonal-sums/
├── diagonal_sums.c
├── diagonal_sums.h
├── main.c
├── Makefile
├── README.md
└── resources/
    ├── correctOut1.txt
    ├── correctOut2.txt
    ├── correctOut3.txt
    ├── correctOut4.txt
    ├── correctOut5.txt
    ├── in1.txt
    ├── in2.txt
    ├── in3.txt
    ├── in4.txt
    └── in5.txt
```