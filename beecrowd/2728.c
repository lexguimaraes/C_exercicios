#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char palavra[51];
    char cobol[6] = {'\0'};
    char cobol1[6] = {'\0'};
    int flag, ind;
    char c;
    while (scanf("%s",&palavra) == 1){
        cobol[0] = '\0';
        cobol1[0] = '\0';
        cobol[0] = tolower(palavra[0]);
        flag = 0;
        ind = 0;
        for(int i = 1; i<strlen(palavra);i++){
            if (flag == 1){
                cobol[ind] = tolower(palavra[i]);
                flag = 0;
            }
            if (palavra[i] == '-'){
                flag = 1;
                c = palavra[i-1];
                cobol1[ind]=tolower(c);
                ind++;
            }

        }

        cobol1[4] = tolower(palavra[strlen(palavra)-1]);
        printf("COBOL1 %s\n COBOL %s\n ",cobol1,cobol);
        if (  ((cobol1[0] == 'c') | (cobol[0]=='c')) && ((cobol1[1] == 'o') | (cobol[1] == 'o')) && ((cobol1[2] == 'b') | (cobol[2] == 'b')) && ((cobol1[3] == 'o') | (cobol[3] == 'o'))&& ((cobol1[4] == 'l') | (cobol[4] == 'l'))){
            printf("GRACE HOPPER\n");
            continue;
        }

        printf("BUG\n");
    }
}
