#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
    char data[101];
    struct Node* next;
    struct Node* ant;
}Node;

Node* insere(Node* l,char* palavra) {
    Node *new = malloc(sizeof(Node));
    if (new == NULL)return NULL;
    strcpy(new->data, palavra);
    new->next = l;
    new->ant = NULL;
    if (l!=NULL)
        l->ant = new;
    return new;
}


void reverse(struct Node** head)
{
    struct Node* temp = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        temp = current->ant;
        current->ant = current->next;
        current->next = temp;
        current = current->ant;
    }

    if (temp != NULL)
        *head = temp->ant;
}

void append(Node** l, char* palavra){
    Node *new = malloc(sizeof(Node));
    if (new == NULL)return;
    Node* p = *l;
    new->next = NULL;
    strcpy(new->data,palavra);
    if (*l == NULL){
        *l = new;
        return;
    }
    while(p->next!= NULL){
        p = p->next;
    }
    p->next = new;
}

void lista_exclui (Node* l){
    for(Node *i = l;i!=NULL;i = i->ant) {
        if (i->ant == NULL) {
            Node *p = l; // ponteiro para o primeiro elemento
            while (p != NULL) { // enquanto não é o último elemento
                Node *t = p->next; /* guarda o ponteiro para o próximo elemento */
                free(p); // libera espaço do elemento corrente
                p = t; // lista passa apontar para o próximo elemento
            }
        }
    }
}

void imprime_lista(Node* l){
    for(Node *i = l;i!=NULL;i = i->ant){
        if (i->ant==NULL){
            for(Node* p = i; p!= NULL; p = p->next){
                if (p->next==NULL)
                    printf("%s\n",p->data);
                else
                    printf("%s ",p->data);
            }
        }
    }

}

void sort(Node* head){
    char palavra[101];
    char palavratmp[101];
    int flag = 0;
    Node* temp;
    Node* ite = head;
    Node* p;
    while(ite!=NULL){
        p = ite;
        strcpy(palavra,ite->data);
        //printf("palavra %s\n",palavra);
        flag = 0;
        //printf("\n %s\n",p->data);
        for(Node*i = ite->next;i!= NULL; i = i->next){

            if (strlen(palavra)<strlen(i->data)){
                //printf("\nCOMPARACAO  %s    %s\n",palavra,i->data);
                strcpy(palavra,i->data);
                temp = i;
                //imprime_lista(head);
                //printf("\n");
                flag = 1;
            }
        }
        if (flag == 1){
            if (p->next!=temp){
                temp->ant->next = temp->next;
                if (temp->next!=NULL)
                    temp->next->ant = temp->ant;
                //printf("TEMP ant %s\n",temp->ant->data);
                //strcpy(palavratmp,temp->ant->next->data);
                temp->ant = p->ant;
                p->ant=temp;
                temp->next=p;
                if (temp->ant!=NULL){
                    temp->ant->next=temp;
                }
                //printf("ANT %s\nP %s\nNEXT %s\n",p->ant->data,p->data,p->next->data);
                ite = p;
                //printf("LISTA\n");
                //imprime_lista(head);
                //printf("\n");
                continue;
            }
            else{
                strcpy(palavratmp,p->data);
                strcpy(p->data,temp->data);
                strcpy(temp->data,palavratmp);
            }
        }
        ite = ite->next;
        //printf("ITE %s\n",ite->data);
        //imprime_lista(head);
    }
}

int main(){

    int n;
    char palavra[2510];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        Node* head = NULL;
        scanf(" %[^\n]",palavra);
        char *token;
        token = strtok(palavra, " ");
        while(token!=NULL){
            head = insere(head,token);
            //imprime_lista(head);
            token = strtok(NULL, " ");
        }
        reverse(&head);
        sort(head);
        //printf("\n\n\n");
        imprime_lista(head);
        lista_exclui(head);
    }
}

