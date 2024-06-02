#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int *vet, int tam,int ind){
    if(tam-ind<=tam/2){
        return;
    }
    int temp = vet[tam-ind-1];
    vet[tam-ind-1] = vet[ind];
    vet[ind] = temp;

    return reverse(vet, tam,ind+1);
}

int main(){
    FILE *words = fopen("word.txt","r");
    if (words == NULL){
        perror("Error opening file");
        return 1;
    }
    char word[100];
    char **wordsc = malloc(sizeof(char*));
    if (wordsc == NULL)
        return 0;
    int *rep =malloc(sizeof(int));
    if (rep == NULL)
        return 0;
    int tam = 0;
    while (fscanf(words, "%99s",word)==1){
        //printf("%s",word);
        int flag = 0;
        for (int i = 0; i<tam;i++) {
            if (strcmp(wordsc[i], word) == 0) {
                rep[i]++;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            wordsc = realloc(wordsc,sizeof(char*) * (tam+1));
            if (wordsc == NULL)
                return 0;
            rep = realloc(rep,sizeof(int) * (tam+1));
            if (rep == NULL)
                return 0;
            wordsc[tam] = strdup(word);
            rep[tam] = 1;
            tam++;

        }
    }
    for (int i = 0; i < tam; i++) {
        printf("%s     %d\n", wordsc[i], rep[i]);
    }
    for (int i = 0; i < tam; i++) {
        free(wordsc[i]);
    }
    free(wordsc);
    free(rep);
    fclose(words);
    return 0;
}
