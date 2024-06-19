#include <stdio.h>
#include <math.h>
#include "palavra.h"

/*double multvetor(const double *v,const double* u,int size){
    double temp = 0;
    for(int i = 0;i<size;i++){
        temp += v[i]*u[i];
    }
    return temp;
}

double normavetor(const double*v, int size){
    double temp = 0;
    for(int i = 0;i<size;i++){
        temp+= pow(v[i],2);
    }
    return sqrt(temp);
}

double cosin(const double*v, const double*u, int size){
    return multvetor(v,u,size)/(normavetor(v,size)*normavetor(u,size));
}

double dist_euclid(const double*v, const double*u, int size){
    double temp;
    double temp1 = 0;
    for(int i = 0; i < size; i++){
        temp = v[i]-u[i];
        temp1 += pow(temp,2);
    }
    return sqrt(temp1);
}*/

int main(){
    double v[3] = {3,4,7};
    double u[3]={-2,3,-5};
    //printf("%f    %f",cosin(v,u,3), dist_euclid(v,u,3));
    palavra* vasco = palavra_cria("time",v,"vasco");
    palavra* flamengo = palavra_cria("time",u,"flamengo");
    printf("%f",dist_euclid(vasco,flamengo,3));



}
