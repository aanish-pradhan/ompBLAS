#ifndef MATRIX
#define MATRIX

// INCLUDE LIBRARIES
#include <omp.h>
#include <stdbool.h> // Boolean type
#include <stdint.h> // Unsigned integers
#include <stdio.h> // I/O
#include <stdlib.h> // Dynamic memory allocation

typedef struct matrixStruct {
	uint64_t rows;
	uint64_t columns;
	double** data;
} Matrix;

// FUNCTIONS
/**
 * Generates the zero matrix with dimensions m x n (see below).
 * 
 * @param numberOfRows Number of rows (m)
 * @param numberOfColumns Number of columns (n)
 * @return Pointer to the new matrix.
 */
Matrix* newMatrix(uint64_t numberOfRows, uint64_t numberOfColumns);

/**
 * Generates an m x n (see below) matrix populated with data. Populates the 
 * matrix by row by default (i.e. matrix elements are filled row-by-row from 
 * left to right). Setting byRow to FALSE populates the matrix column-by-column 
 * from top to bottom.
 * 
 * @param numberOfRows Number of rows (m)
 * @param numberOfColumns Number of columns(n)
 * @param data Array of data
 * @param numberOfElements Number of elements in data
 * @param byRow Populate matrix by row (TRUE by default) or by column (FALSE)
 */
Matrix* newMatrixData(uint64_t numberOfRows, uint64_t numberOfColumns, 
	double* data, uint64_t numberOfElements, bool byRow);

/**
 * Deallocates a matrix from RAM.
 * 
 * @param Pointer to a matrix
 */
void clearMatrix(Matrix* matrix);

/**
 * Prints out a Matrix object.
 * 
 * @param Pointer to a Matrix object. 
 */
void printMatrix(Matrix* matrix);


#endif