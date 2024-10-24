//Programa que resuelve la ecuación de calor 

#include<stdio.h>
#include<math.h>

#define NMAX 100
void LU ();

//Función principal
int main () {

double A[NMAX]={2,-1,3}, C[NMAX]={0,4,-3}, E[NMAX]={1,5,0}, b[NMAX]={7,-2,4};
double x[NMAX];
int i, n=3;

LU (A,C,E,b,n,x);

for(i=0;i<n;i++){
    printf("%lf\n", x[i]);
}

    return 0;
}



//Función  (subrutina)
void LU (double A[NMAX], double C[NMAX], double E[NMAX], double b[NMAX], int n , double x[NMAX]){
    
    double u[NMAX], w[NMAX], y[NMAX];

    int i;

    w[0]=A[0];

    for( i=0 ; i<n-1 ;i++){

        u[i]=E[i]/w[i];
        w[i+1]=A[i+1]-C[i+1]*u[i];

    }

    y[0]=b[0]/w[0];

    for( i=1; i<n ; i++ ){

        y[i]=(b[i]-C[i]*y[i-1])/w[i];
    }

    x[n-1]=y[n-1];

    for( i=n-2 ; i>=0 ; i-- ){

        x[i]=y[i]-u[i]*x[i+1];

    }


}