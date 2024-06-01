
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *vet, unsigned long tam,int ind){
    if(tam-ind<=tam/2){
        return;
    }
    char temp = vet[tam-ind-1];
    vet[tam-ind-1] = vet[ind];
    vet[ind] = temp;

    return reverse(vet, tam,ind+1);
}

int main(){
    char vasco[] = "vascoa";
    reverse(vasco,strlen(vasco),0);
    printf("%s",vasco);
    return 1;
}
