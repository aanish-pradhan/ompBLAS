// INCLUDE LIBRARIES
#include <omp.h>
#include <stdio.h>
#include "matrix.h"

int main(void) {
	printf("ompBLAS: OpenMP Basic Linear Algebra Subroutines\n");

	#ifdef OMP_DEBUG
	{
		#pragma omp parallel
		{
			if (omp_get_thread_num() == 0) {
				printf("OpenMP detected %d thread(s)\n", 
					omp_get_num_threads());
			}
		}
	}
	#endif

	Matrix* matrix = newMatrix(10, 10);
	printMatrix(matrix);
	clearMatrix(matrix);

	return 0;
}