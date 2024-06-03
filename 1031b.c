#include <stdio.h>

int rec(int n,int m,int desl[1000],int tam,int atual){
    if ((atual == 1) & (tam == 0)){
        desl[0] = 1;
        //printf("%d %d\n",desl[tam],tam);
        return rec(n, m, desl,tam+1,2);
    }
    if((m == 1) & (n != 13))
        return rec(n,m+1,desl,0,1);
    int passos = 0;
    int found;
    atual--;
    while(passos<m){
        found = 0;
        atual++;

        if (atual > n)
            atual = 1;
        //printf("%d  ",atual);
        for (int i = 0; i < tam; i++){
            //printf("%d   %d\n",desl[i],atual);
            if (atual==desl[i]){
                found = 1;
            }
        }
        if (found!=1){
            //printf("A %d",passos);
            passos++;
        }



        //printf("%d %d %d\n",atual,passos,m);
    }
    if (tam>=n-1){
        printf("%d\n",m);
        return m;}
    if (atual != 13){
        desl[tam] = atual;
        //printf("%d %d\n",desl[tam],tam);
        return rec(n,m,desl,tam+1,atual);
    }
    if (tam < n-1) {
        for (int i = 0; i < tam; i++) {
            desl[i] = 0;
        }
        return rec(n, m + 1, desl, 0, 1);
    }
    printf("%d\n",m);
    return m;
}





int main(){
    int desl[1000];
    int n;
    while (scanf("%d",&n)==1){
        if (n==0)
            return 0;
        rec(n,1,desl,0,1);
    }
    return 0;
}