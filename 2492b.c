#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node{
    char dominio[31] ;
    char imagem[31] ;
    struct Node* next;
}Node;


Node* insere(Node* l,char* dominio,char* imagem){
    Node* new = malloc(sizeof(Node));
    strcpy(new->imagem,imagem);
    strcpy(new->dominio,dominio);
    new->next = l;
    return new;
}

void imprime_lista(Node* l){
    Node* p = l;
    for(;p!= NULL; p = p->next){
        printf("DOMINIO %s   IMAGEM %s\n",p->dominio,p->imagem);

    }


}

void lista_exclui(Node* l){
    Node* t;
    Node* p = l;
    while(p!= NULL){
        t = p->next;
        free(p);
        p = t;
    }
}

int invertivel(Node *l){
    for(Node* p = l;p!= NULL;p = p->next){
        for(Node* i = p->next;i!= NULL; i = i->next){
            //printf("IMAGEM 1 %s IMAGEM 2%s\n",p->imagem,i->imagem);
            if (strcmp(p->imagem,i->imagem)==0){
                //printf("a\n");
                return 0;}
        }
    }
    return 1;
}


int is_funcao(Node*l){
    for(Node* p = l;p!= NULL;p = p->next){
        for(Node* i = p->next;i!= NULL; i = i->next){
            if (strcmp(p->dominio,i->dominio)==0)
                return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    Node* head;
    char funcao[50];
    while(scanf("%d",&n)!=EOF){
        if (n == 0)
            break;
        head = NULL;
        char imagem[50],dominio[50];
        char*token;
        for(int i = 0;i < n; i++){
            scanf(" %[^\n]",funcao);
            memset(imagem,0,sizeof(imagem));
            memset(dominio,0,sizeof(dominio));
            char* str = funcao;
            token = strstr(str," -> ");
            if (token)
                *token = '\0';
            strcpy(dominio,str);
            if (token)
                str = token + 4;
            strcpy(imagem,str);
            head = insere(head,dominio,imagem);

            //
        }
        if (is_funcao(head)==1){
            if (invertivel(head)==1){
                printf("Invertible.\n");
            }
            else{
                printf("Not invertible.\n");
            }
        }
        else
            printf("Not a function.\n");
        //imprime_lista(head);
        lista_exclui(head);
    }
    return 0;
}