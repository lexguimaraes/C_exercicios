#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* insere(Node* l, int i){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = i;
    new->next = l;
    return new;
}

void lista_imprime(Node* l) {
    Node* p;// ponteiro auxiliar para "andar" na lista
    for (p = l; p != NULL; p = p->next) /* percorre a lista,
apontando para cada
elemento a cada iteração */

        printf("info = %d\n", p->data); /* imprime a

informação armazenada no nó */

}

void lista_exclui (Node* l){
    Node* p = l; // ponteiro para o primeiro elemento
    while (p != NULL) { // enquanto não é o último elemento
        Node* t = p->next; /* guarda o ponteiro para o próximo elemento */
        free(p); // libera espaço do elemento corrente
        p = t; // lista passa apontar para o próximo elemento
    }
}
Node* busca_lista(Node* l, int n){
    for (Node* p = l; p!= NULL;p=p->next){
        if (p->data == n){
            return p;
        }
    }
    return NULL;
}

int busca_ind(Node*l, int n){
    Node *p = l;
    for (int i = 0; i<n;i++){
        if (p->next != NULL)
            p = p->next;
        else
            return -1;
    }
    int num = p->data;
    return num;
}

Node* lista_remove_elem(Node *l, int n){
    Node* ind = NULL;
    Node* p = l;
    while ((p != NULL) && (p->data!=n)){
        ind = p;
        p = p->next;
    }
    if (p == NULL){
        return l;
    }
    if (ind == NULL){
        l = l->next;
    }
    else{
        ind->next = p->next;
    }
    //free(p);
    return l;
}
Node* lista_metade(Node* l){
    Node* start=l;
    Node* startmet = l->next;
    while(startmet != NULL){
        startmet=startmet->next;
        if (startmet!=NULL){
            startmet=startmet->next;
            start=start->next;
        }
    }
    startmet = start->next;
    start->next=NULL;
    return startmet;
}


Node* lista_metaderec(Node*l,Node*ind){
    if (ind == NULL) {
        Node *u = l->next;
        l->next = NULL;
        return u;
    }
    Node* p = l;
    Node* i = ind->next;
    if (i!=NULL){
        return lista_metaderec(p->next,i->next);
    }
    return lista_metaderec(p,i);
}
//REVERTER SÓ ELEMENTOS
void reverse_elements(Node *head){
    if (!head)return;
    int tamanho = 0;
    int ind = 0;
    Node* ultimo = head;
    for(Node* p = head;p!=NULL;p= p->next) {
        tamanho++;
        if (ultimo->next!=NULL)
            ultimo = ultimo->next;
    }
    Node* primeiro = head;
    int temp;
    while(ind<tamanho/2){
        temp = ultimo->data;
        ultimo->data = primeiro->data;
        primeiro->data = temp;
        primeiro = primeiro->next;
        ind++;
        ultimo = head;
        for(int i = 0;i<tamanho-ind-1;i++){
            ultimo = ultimo->next;
        }
    }
}

int main(){
    Node* head = NULL;
    for(int i = 0;i<5;i++){
        head = insere(head, i+1);
    }
    lista_imprime(head);
    printf("REVERSA \n");
    lista_imprime(head);
    lista_exclui(head);

    return 1;
}