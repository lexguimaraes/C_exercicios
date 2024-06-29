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
Node* insere_ind(Node*head,int ind, int data){
    if(ind == 0)return insere(head,data);
    int cont = 0;
    Node* temp = NULL;
    Node* tempnext;
    Node* new = malloc(sizeof(Node));
    new->data = data;
    for(Node* p = head; p!= NULL;p = p->next){
        if (cont >= ind-1){
            temp = p;
            break;
        }
        cont++;
    }
    if (temp == NULL)return head;
    tempnext = temp->next;
    temp->next = new;
    new->next = tempnext;
    return head;
}

Node* append(Node* head,int data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    if (head == NULL)return new;
    Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = new;
    return head;
}

Node* i_p2(Node* head){
    Node* new_head = NULL;
    for(Node* p = head;p!=NULL;p = p->next){
        if(p->data%2==0){
            new_head = append(new_head,p->data);
        }
    }
    for(Node* p = head;p!=NULL;p = p->next){
        if(p->data%2!=0){
            new_head = append(new_head,p->data);
        }
    }
    return new_head;
}

void i_p(Node* head){
    Node* ultp = NULL;
    int temp1;
    int temp;
    for(Node* p = head; p!= NULL; p = p->next){
        if(p->data%2 == 0){
            if (ultp == NULL){
                p = p->next;
                continue;
            }
            temp = ultp->data;
            ultp->data = p->data;
            for(Node* i = ultp->next; i!= p->next;i = i->next){
                temp1 = i->data;
                i->data = temp;
                temp = temp1;
            }
            ultp = ultp->next;
        }
        if(ultp == NULL){
            if(p->data%2!= 0)
                ultp = p;
        }
    }


}

int igual(Node* lista1, Node* lista2){
    Node* p = lista1;
    Node* i = lista2;
    while(p!= NULL && i!= NULL){
        if(p->data != i->data){
            return 0;
        }
        p = p->next;
        i = i->next;
    }
    if(p == NULL && i == NULL){
        return 1;
    }
    return 0;
}


int contrario(Node* lista1, Node* lista2){
    Node* lista_aux  = NULL;
    for(Node* p = lista1; p!= NULL; p= p->next){
        lista_aux = insere(lista_aux,p->data);
    }
    int temp_return = igual(lista_aux,lista2);
    lista_exclui(lista_aux);
    return temp_return;
}

Node* sort_novalista(Node* head){
    Node* lista_nova = NULL;
    for(Node* p = head;p!= NULL;p = p->next){
        lista_nova = insere(lista_nova,p->data);
    }
    int temp;
    int swapped=0;

    for(Node* p = lista_nova;p!= NULL; p = p->next){
        for(Node* i = p->next;i!= NULL; i = i->next){
            if(i->data < p->data){
                temp = i->data;
                i->data = p->data;
                p->data = temp;
            }
        }
    }
    return lista_nova;
}

Node* concat(Node* lista1, Node* lista2){
    Node* temp = NULL;
    for(Node* p = lista1;p!=NULL; p = p->next){
        temp = p;
    }
    if (temp!=NULL){
        temp->next = lista2;
        return lista1;
    }
    return lista2;
}
int main(){
    return 0;
}