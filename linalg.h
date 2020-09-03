#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/**************************************************
*****SOLVING SYSTEM OF LINEAR EQUATIONS WITH*******
*****GAUSS ELIMINATION WITH PARIAL PIVOTING********
**************************************************/
double *gaussElimination(double **M,int m, int n){
    int i,j,k;
    double *x;
    x = malloc(m*sizeof(double *));
    for(i=0;i<m-1;i++){
        //Partial Pivoting
        for(k=i+1;k<m;k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(M[i][i])<fabs(M[k][i])){
                //Swap the rows
                for(j=0;j<n;j++){                
                    double temp;
                    temp=M[i][j];
                    M[i][j]=M[k][j];
                    M[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<m;k++){
            double  term=M[k][i]/ M[i][i];
            for(j=0;j<n;j++){
                M[k][j]=M[k][j]-term*M[i][j];
            }
        }
         
    }
    //Begin Back-substitution
    for(i=m-1;i>=0;i--){
        x[i]=M[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-M[i][j]*x[j];
        }
        x[i]=x[i]/M[i][i];
    }
    return x;

}

void solution_GaussEl(double *x,int n){
    int i;
    printf("\nThe solution is: \n");
    for(i=0; i<n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
}
/**************************************************
*****SOLVING SYSTEM OF LINEAR EQUATIONS WITH*******
*****GAUSS Jordan ELIMINATION **********************
**************************************************/
double *gaussJordan(double **M,int n){
    int i,j,k;
    double c;
    double *x;
    x = malloc(30*sizeof(double *));
   /* Now finding the elements of diagonal matrix */
    for(j=0; j<=n; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(i!=j)
            {
                c=M[i][j]/M[j][j];
                for(k=0; k<n+1; k++)
                {
                    M[i][k]=M[i][k]-c*M[j][k];
                }
            }
        }
    }
    for(i=0; i<=n; i++)
    {
        x[i]=M[i][n+1]/M[i][i];
    }
    return x;
}







void *Transpose(double **M, int dim) {
    double **L;
    int i,j;
    
    
    L = malloc( dim*dim*sizeof(int *));
    
    for (i=0; i<dim; i++) 
        for (j=0; j<dim; j++) 
            L[i+dim*j] = M[j+dim*i];
        
    return L;
}     

void Squaring(int *M, int dim) {
    int i,j;
    
    for (i=0;i<dim;i++)
        M[i]=M[i] * M[i];
        
}
