/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	// printf("NEOPT SOLVER\n");	
	int i, j, k;
	double sum;
	double *C = (double *)malloc(sizeof(double) * N * N);
	double *A2 = (double *)malloc(sizeof(double) * N * N);

	if (C == NULL || A2 == NULL ) {
      free(C);
	  free(A2);
      return NULL;
    }

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			sum = 0;
			if (i <= j)
				for (k = i; k < N; k++)
					sum += A[i * N + k] * A[k * N + j];
			if (sum != 0)
				A2[i * N + j] = sum;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			sum = 0;
			for (k = j; k < N; k++)
				sum += B[i * N + k] * A[j * N + k];
			C[i * N + j] = sum;
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			sum = 0;
			for (k = i; k < N; k++)
				sum += A2[i * N + k] * B[k * N + j];
			if (sum != 0)
				C[i * N + j] += sum;
		}
	}

	free(A2);
	return C;
}
