/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	// printf("OPT SOLVER\n");
	int i, j, k;
	double *C = (double *)malloc(sizeof(double) * N * N);
	double *A2 = (double *)malloc(sizeof(double) * N * N);

	if (C == NULL || A2 == NULL ) {
		free(C);
		free(A2);
		return NULL;
	}
	// A2 
	for (i = 0; i < N; i++)
	{
		double *orig_paa = &A[i*N+i];
		for (j = 0; j < N; j++)
		{
			double *paa = orig_paa;
    		double *pba = &A[i*N+j];
			register double sum = 0;
			if (i <= j)
				for (k = i; k < N; k++)
				{
					sum += *paa * *pba;
					paa++;
					pba += N;
				}
			if (sum != 0)
				A2[i * N + j] = sum;
		}
	}

	//C=B*A
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			double *pab =  &B[i*N+j];
    		double *pba = &A[j*N+j];
			register double sum = 0;
			for (k = j; k < N; k++)
			{
				sum += *pab * *pba;
				pab++;
				pba++;
			}
			C[i * N + j] = sum;
		}
	}

	//C=C+A2*B
	for (i = 0; i < N; i++)
	{
		double *orig_paa2 = &A2[i*N+i];
		for (j = 0; j < N; j++)
		{
			double *paa2=orig_paa2;
			double *pbb = &B[i*N+j];
			register double sum = 0;
			for (k = i; k < N; k++) {
				sum += *paa2 * *pbb;
				paa2++;
				pbb+=N;
			}
			if (sum != 0)
				C[i * N + j] += sum;
		}
	}

	free(A2);
	return C;
}
