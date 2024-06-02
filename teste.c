#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Person{
    char name[64];
    int age[10];
};

char** lerfile(int *tam){
    char **nomes = malloc(sizeof(char*));
    if(nomes == NULL)
        return 0;
    FILE *fnomes = fopen("word.txt","r");
    if (fnomes == NULL){
        perror("Error opening file");
        free(nomes);
        return 0;
    }
    char temp[30];
    while (fscanf(fnomes,"%s",temp)==1){

        nomes = realloc(nomes,sizeof(char*)*(*tam+1));
        if (nomes == NULL){
            fclose(fnomes);
            return 0;}
        nomes[*tam] = strdup(temp);
        //printf("%s\n",nomes[tam]);
        (*tam)++;
    }
    fclose(fnomes);
    return nomes;
}

void freearr(char **arr, int tam){
    for (int i = 0;i < tam; i++){
        free(arr[i]);
    }
}

void updateage(struct Person *p, const int *age,const int size_a,int size,char **nomes,const int tam){
    char buffer[400];
    char temp[10];
    unsigned int esp = 0;
    for(int i = 0 ; i<tam; i++){
        if (strlen(nomes[i]) > esp)
            esp = strlen(nomes[i]) + 4;
    }



    for (int j = 0; j<size ;j++){
        strcpy(p[j].name, nomes[j]);
        printf("%s",p[j].name);
        for(int k = 0; k < esp-strlen(p[j].name); k++){
            printf(" ");
        }
        for (int i = 0; i < size_a ; i++){
            p[j].age[i] = age[i];
            printf("%d",p[j].age[i]);
        }
        printf("\n");
    }

}
int main() {
    //char **nomes = malloc(sizeof(char*));
    struct Person *vasco = malloc(10*sizeof(struct Person));
    int a[5]= {1,2,3,4,5};
    int tam = 0;
    char **nomes = lerfile(&tam);
    updateage(vasco,a ,5,10,nomes,tam);
    free(vasco);
    freearr(nomes,tam);
    free(nomes);
    return 0;
}