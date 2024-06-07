#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data[100];
    struct Node* next;
    struct Node* ant;
}Node;


Node* insere(Node* l,char* palavra){
    Node* new = malloc(sizeof(Node));
    if (new == NULL)return NULL;
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
        scanf("%d %d\n", &n, &m);
        char musica[m][81];
        char palavra[64];
        for (int j = 0; j < n * 2; j++) {
            fgets(palavra,62,stdin);
            palavra[strcspn(palavra,"\n")]=0;
            head = insere(head, palavra);
            if (head == NULL){
                fprintf(stderr, "Memory allocation failed\n");
                return 0;
            }
        }
        for(int y = 0;y<m;y++){
            fgets(palavra,62,stdin);
            strcpy(musica[y],palavra);
            const char s[2] = " ";
            char *token;
            char trad[300];
            token = strtok(musica[y], s);

            while( token != NULL ) {
                token[strcspn(token,"\n")]=0;
                //printf("%s ",token);
                strcpy(trad,lista_busca(head, token));
                printf("%s ",trad);
                token = strtok(NULL,s);
            }
            printf("\n");
        }
        printf("\n");
        lista_exclui(head);
    }
    return 0;
}