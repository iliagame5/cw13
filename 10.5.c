#include<stdio.h>
#include <stdlib.h>
#include<complex.h>
#include<stdbool.h>
#include<assert.h>

bool in_set(complex c,int n){
    complex z=0;
        for (;n--;)
            z=z*z+c;
        return cabs(z)<=2;


}
int main(int argc, char*argv[]){
    assert(argc==5);
    double x_min=atof(argv[1]), x_max=atof(argv[2]), y_min=atof(argv[3]), y_max=atof(argv[4]);

    for(int i=0; i<=1024; i++)
        for(int j=0; j<=1024; j++){
            double x=x_min+i*(x_max-x_min)/1024.;
            double y=y_min+j*(y_max-y_min)/1024.;
            complex c=x+y*I;
            if(in_set(c,20))
                    printf("%g\t%g\n",x,y);

        }




}
