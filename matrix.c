// INCLUDE LIBRARIES
#include "matrix.h"

// FUNCTIONS
/**
 * Generates the zero matrix with dimensions m x n.
 * 
 * @param numberOfRows Number of rows
 * @param numberOfColumns Number of columns
 * @return Pointer to the new matrix.
 */
Matrix* newMatrix(uint64_t numberOfRows, uint64_t numberOfColumns){
	// Preconditions
	if (numberOfRows == 0 || numberOfColumns == 0) {
		printf("Error! Illegal matrix dimensions. ");
		printf("Number of rows and columns must be greater than 0\n");
		exit(1);
	}

	// Allocate RAM for a new Matrix object
	Matrix* matrix = malloc(sizeof(Matrix));
	
	// Set dimensions
	matrix->rows = numberOfRows;
	matrix->columns = numberOfColumns;
	
	// Allocate RAM for the matrix elements
	matrix->data = malloc(sizeof(double*) * numberOfRows);

	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < numberOfRows; i++) {
			matrix->data[i] = calloc(numberOfColumns, sizeof(double));
		}

		#ifdef OMP_DEBUG
		{
			if (omp_get_thread_num() == 0) {
				printf("Allocated a %ld x %ld matrix with %d thread(s)\n", 
				numberOfRows, numberOfColumns, omp_get_num_threads());
			}
		}
		#endif
	}

	return matrix;
}

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
	double* data, uint64_t numberOfElements, bool byRow) {
	// Preconditions

	// 1. Valid matrix dimensions
	if (numberOfRows == 0 || numberOfColumns == 0) {
		printf("Error! Illegal matrix dimensions. ");
		printf("Number of rows and columns must be greater than 0\n");
		exit(1);
	}

	// 2. Sufficient data elements
	if (numberOfElements != numberOfRows * numberOfColumns) {
		printf("Error! Insufficient number of data elements. ");
		printf("numberOfElements must equal numberOfRows * numberOfColumns\n");
		exit(1);
	}

	// Allocate RAM for a new Matrix object
	Matrix* matrix = malloc(sizeof(Matrix));
	
	// Set dimensions
	matrix->rows = numberOfRows;
	matrix->columns = numberOfColumns;
	
	// Allocate RAM for the matrix elements
	matrix->data = malloc(sizeof(double*) * numberOfRows);

	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < numberOfRows; i++) {
			matrix->data[i] = calloc(numberOfColumns, sizeof(double));
		}

		#ifdef OMP_DEBUG
		{
			if (omp_get_thread_num() == 0) {
				printf("Allocated a %ld x %ld matrix with %d thread(s)\n", 
				numberOfRows, numberOfColumns, omp_get_num_threads());
			}
		}
		#endif
	}

	// Populate the matrix
	if (byRow == false) { // Populate by column
		// TODO
	}
	else { // Populate by row
		// TODO
	}

	return matrix;
}

/**
 * Deallocates a matrix from RAM.
 * 
 * @param Pointer to a matrix
 */
void clearMatrix(Matrix* matrix) {
	// Deallocate rows of the matrix
	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < matrix->rows; i++) {
			free(matrix->data[i]);
			matrix->data[i] = NULL;
		}
	}

	// Deallocate the data attribute of the matrix
	free(matrix->data);
	matrix->data = NULL;
	
	// Deallocate the matrix
	matrix->rows = 0;
	matrix->columns = 0;
	free(matrix);
	matrix = NULL;
}

/**
 * Prints out a Matrix object.
 * 
 * @param Pointer to a Matrix object.
 */
void printMatrix(Matrix* matrix) {
	printf("Matrix at %p: %ld x %ld \n", matrix, matrix->rows, 
		matrix->columns);
	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			printf("%g ", matrix->data[i][j]);
		}
		printf("\n");
	}
}