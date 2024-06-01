#include <stdio.h>
#include <stdlib.h>

void leia_matriz(int n,double matriz[n][n]){
    for (int i = 0;i <n;i++){
        for (int j = 0;j<n;j++){
            scanf("%lf",&matriz[i][j]);
        }
    }
}
void tmatriz(int n, double matriz[n][n],double m[n][n]){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            matriz[i][j] = m[j][i];
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    double matriz[n][n];
    leia_matriz(n,matriz);
    double matrizt[n][n];
    tmatriz(n,matrizt,matriz);
    double rmatriz[n][n];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            rmatriz[i][j] = 0;
            for(int a = 0;a<n;a++){
                rmatriz[i][j] += matriz[i][a] * matrizt[a][j];
            }

        }
    }
    /*for (int i = 0; i<n; i++){
        puts("");
        for (int j = 0; j<n; j++){
            printf("%.0f ",rmatriz[i][j]);
        }
    }*/
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i == j){
                if (rmatriz[i][j] != 1){
                    printf("NAO ORTOGONAL");
                    return 0;
                }
            }
            else{
                if (rmatriz[i][j] != 0){
                    printf("NAO ORTOGONAL");
                    return 0;
                }
            }
        }
    }
    printf("ORTOGONAL");
    return 1;
}