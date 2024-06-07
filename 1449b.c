#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data[300];
    struct Node* next;
    struct Node* ant;
}Node;


Node* insere(Node* l,char* palavra){
    Node* new = malloc(sizeof(Node));
    strcpy(new->data,palavra);
    new->next = l;
    new->ant = NULL;
    if (l!=NULL){
        l->ant = new;
    }

    return new;
}
void imprime_lista(Node* l){
    for(Node* p = l;p != NULL;p = p->next){
        printf("%s\n",p->data);
    }
}

char* lista_busca(Node* l, char* palavra){
    for(Node* p = l ;p!=NULL;p = p->next){
        //printf("%s  %s\n",palavra, p->data);
        if (strcmp(p->data,palavra)==0){
            Node* temp = p->ant;
            //printf("BUSCADO: %s\n",temp->data);
            return temp->data;
        }
    }
    return palavra;
}

void lista_exclui (Node* l){
    Node* p = l; // ponteiro para o primeiro elemento
    while (p != NULL) { // enquanto não é o último elemento
        Node* t = p->next; /* guarda o ponteiro para o próximo elemento */
        free(p); // libera espaço do elemento corrente
        p = t; // lista passa apontar para o próximo elemento
    }
}


int main(){

    int k;
    scanf("%d",&k);
    for (int i = 0;i<k;i++) {
        Node* head = NULL;
        int n, m;
        int t = 0;
        scanf("%d %d\n", &n, &m);
        char musica[m][81];
        char palavras[81*m][81];
        char palavra[64];
        for (int j = 0; j < n * 2; j++) {
            fgets(palavra,63,stdin);
            palavra[strlen(palavra)-1]='\0';
            head = insere(head, palavra);
        }
        for(int y = 0;y<m;y++){
            fgets(palavra,63,stdin);
            strcpy(musica[y],palavra);
        }
        for (int j = 0; j < m;j++){
            const char s[2] = " ";
            char *token;
            char trad[300];
            /* get the first token */
            token = strtok(musica[j], s);

            /* walk through other tokens */
            while( token != NULL ) {
                token[strcspn(token,"\n")]=0;
                //printf("%s ",token);
                strcpy(trad,lista_busca(head, token));
                printf("%s ",trad);
                t++;
                token = strtok(NULL, s);

            }
            printf("\n");
        }
        /*for (int u = 0;u<t;u++){
            palavras[u][strcspn(palavras[u], "\n")] = 0;

            strcpy(trad,lista_busca(head, palavras[u]));
            printf("%s ",trad);
        }*/
        printf("\n");
        lista_exclui(head);
    }
    return 1;
}