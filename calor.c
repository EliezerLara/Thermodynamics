//Programa que resuelve la ecuación de calor 

#include<stdio.h>
#include<math.h>

#define NMAX 100
#define f(x) (4.0*(x)*(1-(x)))

void LU ();

//Función principal
int main () {

double A[NMAX], C[NMAX] , E[NMAX] , b[NMAX];
double x[NMAX] , h=0.01 , ua=0.0 , ub=0.0 ;
int i, n;

n=floor(1.0/h)-1;

FILE*arch=fopen("calor.txt", "w");

for(i=0;i<n;i++){

    A[i]=-2.0/(h*h);
    C[i]=1.0/(h*h);
    E[i]=1.0/(h*h);
    b[i]=f((i+1)*h);

}

// Condiciones de frontera de Dirichlet

b[0] -= ua/(h*h);
b[n-1] -= ub/(h*h);

LU (A,C,E,b,n,x);

//Impresión de los datos en el archivo de texto

fprintf(arch, "%lf %lf\n", 0.0 , ua );

for( i=0 ; i<n ; i++){

    fprintf(arch, "%lf %lf\n", (i+1)*h , x[i]);

}

fprintf(arch, "%lf %lf\n", 1.0 , ub );

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