#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palavra[31];
    while (scanf("%s",palavra)==1){
        for(int i = 1; i<= strlen(palavra)/2;i++){
            if(strncmp(&palavra[strlen(palavra)-i],&palavra[strlen(palavra)-2*i],i)==0){
                palavra[strlen(palavra)-i] ='\0';
                break;
            }
        }
        printf("%s\n",palavra);
    }
    return 0;
}