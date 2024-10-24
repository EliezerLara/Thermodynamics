#include <stdio.h>
#include <math.h>
#define NMAX 200
#define f(x) (exp((x)))
#define g(t) (exp(1)*(1-((t)*(t))))

void LU ();

int main(){

	double A[NMAX], C[NMAX], E[NMAX], b[NMAX];
	double h=0.01, ua=1.0, ub, r=10.0, k, c=1.0, t=1.0;
	double u0[NMAX];
	int i,n,j,m;

k=r*h*h/(c*c);
n=floor(1.0/h)-1;
m=floor(t/k)+1;
ub=g(0);

FILE*arch=fopen("uno.txt", "w");

//Condiciones iniciales

fprintf(arch, "%lf %lf %lf\n", 0.0, 0.0 , ua );

for(i=0; i<n ;i++){
	u0[i]=f((i+1)*h);
	fprintf(arch, "%lf %lf %lf\n", (i+1)*h, 0.0 , u0[i]);
}

fprintf(arch, "%lf %lf %lf\n", 1.0, 0.0 , g(0) );


fprintf(arch,"\n");

// Definición de la matriz

for(i=0;i<n;i++){
	A[i]=(2+2*r);
	C[i]=-r;
	E[i]=-r;
}

//Condiciones de frontera 

for(j=0;j<=m; j++){


	b[0]=(2-2*r)*u0[0]+r*u0[1]+2*r*ua;
	b[n-1]=(2-2*r)*u0[n-1]+r*u0[n-2]+2*r*ub;

	for(i=1; i<n-1; i++){
		b[i]=(2-2*r)*u0[i]+r*(u0[i-1]+u0[i+1]);
	}

	LU (A,C,E,b, n, u0);

	ub=g((j+1)*k);

	fprintf(arch, "%lf %lf %lf\n", 0.0, (j+1)*k , ua );

	for (i=0;i<n;i++){
		fprintf(arch, "%lf %lf %lf\n", (i+1)*h, (j+1)*k , u0[i]);
	}

	fprintf(arch, "%lf %lf %lf\n", 1.0, (j+1)*k , ub);

	fprintf(arch,"\n");
}

}

void LU (double A[NMAX], double C[NMAX], double E[NMAX], double b[NMAX], int n, double x[NMAX]){

double u[NMAX], w[NMAX], y[NMAX];
int i;

w[0]=A[0];

for (i=0;i<n-1;i++){
	u[i]=E[i]/w[i];
	w[i+1]=A[i+1]-C[i+1]*u[i];
}

y[0]=b[0]/w[0];

for (i=1;i<n;i++){
	y[i]=(b[i]-C[i]*y[i-1])/w[i];
}

x[n-1]=y[n-1];

for (i=n-2;i>=0;i--){
	x[i]=y[i]-u[i]*x[i+1];
}
	
	
}
	
