#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
#pragma ide diagnostic ignored "EndlessLoop"
void morse(char *tmp){
    if(strcmp( tmp, "=.===") == 0) printf("a");
    else if(strcmp( tmp, "===.=.=.=") == 0) printf("b");
    else if(strcmp( tmp, "===.=.===.=") == 0) printf("c");
    else if(strcmp( tmp, "===.=.=") == 0) printf("d");
    else if(strcmp( tmp, "=") == 0) printf("e");
    else if(strcmp( tmp, "=.=.===.=") == 0) printf("f");
    else if(strcmp( tmp, "===.===.=") == 0) printf("g");
    else if(strcmp( tmp, "=.=.=.=") == 0) printf("h");
    else if(strcmp( tmp, "=.=") == 0) printf("i");
    else if(strcmp( tmp, "=.===.===.===") == 0) printf("j");
    else if(strcmp( tmp, "===.=.===") == 0) printf("k");
    else if(strcmp( tmp, "=.===.=.=") == 0) printf("l");
    else if(strcmp( tmp, "===.===") == 0) printf("m");
    else if(strcmp( tmp, "===.=") == 0) printf("n");
    else if(strcmp( tmp, "===.===.===") == 0) printf("o");
    else if(strcmp( tmp, "=.===.===.=") == 0) printf("p");
    else if(strcmp( tmp, "===.===.=.===") == 0) printf("q");
    else if(strcmp( tmp, "=.===.=") == 0) printf("r");
    else if(strcmp( tmp, "=.=.=") == 0) printf("s");
    else if(strcmp( tmp, "===") == 0) printf("t");
    else if(strcmp( tmp, "=.=.===") == 0) printf("u");
    else if(strcmp( tmp, "=.=.=.===") == 0) printf("v");
    else if(strcmp( tmp, "=.===.===") == 0) printf("w");
    else if(strcmp( tmp, "===.=.=.===") == 0) printf("x");
    else if(strcmp( tmp, "===.=.===.===") == 0) printf("y");
    else if(strcmp( tmp, "===.===.=.=") == 0) printf("z");

}


int main(){
    char frase[1001];
    int n;
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        memset(frase,0,sizeof(frase));
        scanf(" %[^\n]",frase);
        char* str = frase;
        char* token;
        char* token2;
        int flag = 0;
        do{

            token = strstr(str,".......");
            if (token!=NULL){
               *token = '\0';
            }
            else
                flag = 1;
            do{
                token2 = strstr(str,"...");
                if (token2)
                    *token2='\0';
                morse(str);
                if (token2)
                    str = token2+3;
            }while(token2!=NULL);
            if(token)
                str = token+7;
            if (!flag)
                printf(" ");
        }while(token!=NULL);
        printf("\n");
    }
    return 0;

}
#pragma clang diagnostic pop