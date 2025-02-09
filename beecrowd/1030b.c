#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void lista_imprime1(Node* l,int tam) {
    Node* p = l;// ponteiro auxiliar para "andar" na lista
    for (int i = 0; i<tam; i++){/* percorre a lista,
apontando para cada
elemento a cada iteração */

        printf("info = %d\n", p->data);
        p = p->next;
    }
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



Node* append(Node* head,int data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    Node* p = head;
    if (p == NULL){
        return new;
    }
    while (p->next!= NULL){
        p = p->next;
    }
    p->next  = new;
    return head;
}





void matar(Node* l,int saltos,int lastdeath,int n){
    Node* p = l;
    if(lastdeath == 0){
        lastdeath = 2;
        for(int i = 0;i < saltos-2; i++){
            p = p->next;
            lastdeath++;
        }
        Node* t = p->next;
        if (p->next->next!= NULL){
            p->next = p->next->next;
            free(t);
            lista_imprime(l);
            matar(l,saltos,lastdeath,n);
        }
        return;
    }
    int temp = lastdeath;
    for(int i = 0; i < saltos - 3 + temp;i++){
        if (p->next == NULL){
            lista_imprime(l);
            return;
        }
        p = p->next;
        lastdeath++;
    }
    printf("%d",p->data);
    Node* t = p->next;
    if (p->next->next!= NULL && p->next!=NULL){
        p->next = p->next->next;
        free(t);
        lista_imprime(l);
        matar(l,saltos,lastdeath,n);
    }
}



int main(){
    Node* head;
    int c,n,saltos;
    scanf("%d",&c);
    for(int i = 0; i < c; i++){
        head = NULL;
        scanf("%d %d",&n, &saltos);
        for (int j = 0;j<n;j++){
            head = append(head,j+1);
        }
        matar(head,saltos,0,n);
    }
}