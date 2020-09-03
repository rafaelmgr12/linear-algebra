#include <stdio.h>
#include <stdlib.h>
#include "read.h"
#include "linalg.h"

#define SIZE 90
main()
{

    double **M, *sol1, *sol2, **B;
    
    sol1 = malloc(SIZE * sizeof(double *));
    sol2 = malloc(SIZE * sizeof(double *));
    

    M = read_2("matrix1.dat", 3, 4);
    show_2(M, 3, 4);

    printf("\nCompute the Gauss Elimination Method\n\n ");
    sol1 = gaussElimination(M, 3, 4);
    solution_GaussEl(sol1, 3);

    printf("\n\n\n\n");
    
    B = read_2("matrix1.dat", 3, 4);
    show_2(B, 3, 4);
    
    printf("\nCompute the Gauss Jordan Method\n\n ");

    sol2 = gaussJordan(B,3);
    solution_GaussJ(sol2, 3);
}
