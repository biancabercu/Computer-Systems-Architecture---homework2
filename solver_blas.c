/*
 * Tema 2 ASC
 * 2020 Spring
 */
#include "utils.h"
#include "cblas.h"


/* 
 * Add your BLAS implementation here
 */
double *my_solver(int N, double *A, double *B)
{
	// printf("BLAS SOLVER\n");
	int m, n, k;
    double alpha, beta;
	double *A2 = (double *)malloc(sizeof(double) * N * N);
	double *C = (double *)malloc(N*N*sizeof(double));

	if (C == NULL || A2 == NULL ) {
      free(C);
	  free(A2);
      return NULL;
    }

	m=N;n=N;k=N;
	alpha=1.0;beta=0.0;
// C=alpha*A*B+beta*C  unde C=B*At
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans,
           m, n, k, alpha, B, k, A, n, beta, C, n);
//  C=alpha*A*B+beta*C  unde A2=A*A
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
		 N, N, N, alpha, A, N, A, N, beta, A2, N);

	beta=1.0;
// C=alpha*A*B+beta*C unde C=A2*B + C 
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
		 N, N, N, alpha, A2, N, B, N, beta, C, N); 

	free(A2);
	return C;
}
