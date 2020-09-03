#include <stdio.h>
#include <stdlib.h>

/*
This set of function read a NxN matrix with line without values
and then show the "fix" matriz.


*/

double **read_1(char *nome){
    double **M;
	int i,j,dim;
    double a;
	FILE *data;

    data = fopen("matriz.dat", "r");
	i = fscanf(data,"%d",&dim);
	
	M = malloc( dim*sizeof(double *));
	for( i = 0 ; i < dim ; i++ ) {
		M[i] = malloc((dim)*sizeof(double) );
	}    
	i = j = 0;
	
	while ( fscanf(data,"%lf",&a) != EOF) {
		M[i][j] = a;
		j++;
		if (j == dim) {
			j = 0;
			i++;
		}
	}		
	return M;  
}    

void show_1(double **M,int dim) {
    int i,j;
     for (i=0; i<dim; i++) {
        for (j=0; j<dim; j++) 
            printf("%g ",M[i][j]);
        puts("");
     }   
}

/* This set of functios read a NxM matrix, that you need to give in the main function

*/

double **read_2(char *nome,int m, int n) {
    double **M;
    int i,j;
    FILE *data;
    
    M=malloc(m*n*sizeof(double *));
    for(i=0;i<m;i++) M[i]=malloc(n*sizeof(double));
    data=fopen(nome,"r");
    for (i=0; i<m; i++) 
        for (j=0; j<n; j++) 
            fscanf(data,"%lf",&M[i][j]);
    fclose(data);
    return M;     
}    
double show_2(double **M, int m, int n) {
    int i,j;
     for (i=0; i<m; i++) {
        for (j=0; j<n; j++) 
            printf("%g ",M[i][j]);
        puts("");
     }   
}