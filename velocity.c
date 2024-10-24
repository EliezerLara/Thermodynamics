/* Programa que resuelve la segunda Ley de Newton utilizando el método de Velocity-Verlet
    
*/

#include <stdio.h>
#include <math.h>

#define a(x) (-(x)/m)  // Definimos la aceleración en términos de la posición 
#define F(x) (-k*x)  //Aquí podemos definir la fuerza del problema a resolver para que el programa nos dé la solución del problema
#define Pi (3.14159)

int main () {
    int j=0, N=200;
    float h=(2*M_PI)/N, x[1000], v[1000], E[1000];
    float m=1, k;


    x[0]=1;
    v[0]=0;
    E[0]=((x[0]*x[0])+v[0]*v[0])/2;


    FILE*arch=fopen("verlet.txt","w"); 

        for(j=0;j<=N;j++){

            x[j+1]=x[j]+v[j]*h+a(x[j])/2*h*h;     //Aproximación con diferencias centradas        
            v[j+1]=v[j]+(a(x[j])-a(x[j+1]))*h/2;       
            E[j]=((x[j]*x[j])+v[j]*v[j])/2;

        }
    
        for(j=0;j<=100;j++){
            fprintf(arch, "%lf %lf %lf %lf\n", x[j], v[j], E[j], j*h);    
                                                        
        }
    fclose(arch); 






    return 0;
}