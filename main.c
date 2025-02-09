#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
void tri();

void acima_da_diagonal();

void print_array(int *arr,int size);

void print_matrix(int lin, int col, int **arr);

float sum(float arr[],int size, int start);

void criar_matriz(int lin,int col, float matriz[lin][col]);

int partition(int start, int end,int *lista);

void sort(int arr[],int first, int last);

void quadrado(int m, int n);

int numDigits(unsigned long long int number) {
    int digits = 0;
    if (number == 0)
        return 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}


int teste(int n, int matriz[n][n],int sum){//5 3 1
    //printf("SUMM %d", sum);
    if (n % 2 != 0){
        for (int i = sum;i < n - sum;i++) {
            for (int j = sum; j < n - sum; j++) {
                matriz[i][j] = 1+sum;
            }
        }
    }
    else{
        for (int i = sum;i<n - sum ;i++){//6 4 1
            for(int j = sum;j < n - sum;j++){
                matriz[i][j] = 1+sum;
            }
        }

    }
    if (sum+1 <= n/2 ){
        teste(n,matriz,  sum+1);
    }
    return 0;
}

int **criarMatriz(int l,int c){
    int **m = malloc(sizeof(int*)*l);
    if (m == NULL)
        return 0;
    for (int i = 0; i < l;i++){
        m[i] = malloc(sizeof(int)*c);
        if (m[i] == NULL){
            for(int j = 0; j < i; j++)
                free(m[j]);
            free(m);
            return 0;
        }
        for (int j = 0; j<c; j++){
            scanf("%d",&m[i][j]);
        }
    }
    return m;
}


void tes(int** data){
    (*data)+=2;

}

double raiz2(int n){
    if (n == 0)return 0;
    return 1/(2+raiz2(n-1));
}

int div2(int x){
    return x/2;
}
int mult2(int x){
    return x*2;
}

int teste1(int x, int (*function)(int)){
   return function(x);
}

struct aaa{
    char a[100];
};

int random(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void quicksort(int start, int end, int* lista){
    if(end <= start) return;
    int pivot = partition(start,end,lista);
    quicksort(start, pivot-1,lista);
    quicksort(pivot+1,end,lista);
}

int partition(int start, int end, int* lista){
    int pivot = lista[end];
    int aux = start-1;
    int temp;
    for(int i = start; i<= end;i++){
        if(lista[i]<=pivot){
            aux++;
            if(lista[i]<lista[aux]){
                temp = lista[aux];
                lista[aux] = lista[i];
                lista[i] = temp;
            }
        }
    }
    return aux;
}
int main ()
{
    srand(time(0));
    int lista[10] = {3,5,6,7,9,2,1,14,8,4};
    quicksort(0,9,lista);
    //print_array(lista,10);
    return 1;
}






void quadrado(int m, int n){
    long long unsigned int matriz[m][m];
    long long unsigned int temp = 0;
    for (int i = 0; i < m;i++){
        for (int j = 0; j<m;j++){
            scanf("%llu", &temp);
            matriz[i][j] = temp*temp;
        }
    }
    printf("Quadrado da matriz #%d:\n",n+4);
    for (int i = 0; i < m;i++) {
        for (int j = 0; j < m; j++) {
            unsigned long long int maior = 0;
            int dig;
            for (int k = 0;k<m;k++){
                if (matriz[k][j] > maior){
                    maior = matriz[k][j];
                }
            }
            dig = numDigits(maior)- numDigits(matriz[i][j]);
            for (int o = 0; o < dig;o++){
                printf(" ");
            }
            if (j == m-1){
                printf("%llu\n",matriz[i][j]);
            }
            else
                printf("%llu ", matriz[i][j]);
        }
    }
}









float sum (float arr[], int size, int start){
    float sum = 0;
    for (int i = start; i < size; i++){
        sum += arr[i];
    }
    return sum;
}



void criar_matriz(int lin,int col, float matriz[lin][col]){
    for(int i = 0; i<lin;i++){
        for (int j = 0; j <col;j++){
            scanf("%f",&matriz[i][j]);
        }
    }
}


void acima_da_diagonal(){
    char c;
    scanf("%c", &c);
    float matrix[12][12];
    int temp;
    float soma = 0;
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            scanf("%f",&matrix[i][j]);
        }
    }
    for (int i = 0; i < 12; i++){
        soma += sum(matrix[i], ARRAY_SIZE(matrix[i]), i+1);
    }
    if (c == 'S'){
        printf("%.1f",soma);
    }
    else{
        printf("%.1f",soma/66);
    };
}



void print_array(int *arr, int size){
    for (int i = 0; i < size ; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}



void print_matrix(int lin,int col, int** arr){
    for (int i = 0 ; i < lin ; i++){
        print_array(arr[i],col );
    }
}



void tri(){
    unsigned long long fib;
    unsigned long long ant;
    unsigned long long temp;
    int n;
    int cont;
    while (scanf("%d", &n)== 1) {
        //if (n == EOF)
        //  break;
        fib = 1;
        ant = 1;
        cont = 0;
        while (cont < n) {
            fib += ant;
            ant = fib - ant;
            if (fib % 3 == 0) {
                cont++;
                continue;
            }
            temp = fib;
            do {
                if (temp % 10 == 3) {
                    cont++;
                    break;
                }
                temp /= 10;
            } while (temp >= 3);
        }
        printf("%llu\n", fib);
    }
}

