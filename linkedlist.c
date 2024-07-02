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
    free(p);
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
        if(p->data%2 != 0){
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
            if(p->data%2== 0)
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
    if(head == NULL)return NULL;
    Node* lista_nova = NULL;
    for(Node* p = head;p!= NULL;p = p->next){
        lista_nova = insere(lista_nova,p->data);
    }
    int temp;
    int swapped=0;
    Node* p;
    Node* end = NULL;
    if(lista_nova==NULL)return NULL;
    do{
        swapped = 0;
        p = lista_nova;
        while(p->next!= end){
            if(p->data > p->next->data){
                temp = p->next->data;
                p->next->data = p->data;
                p->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
        end = p;
    }while(swapped);
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
void cross(Node* l1, Node* l2, int N){
    if(l1 == NULL || l2 == NULL)return;
    Node* ocor1 = NULL;
    Node* antocor1;
    Node* ocor2 = NULL;
    Node* antocor2;
    for(Node* p = l1;p->next!=NULL;p = p->next){
        if(p->next->data == N){
            ocor1 = p->next;
            antocor1 = p;
            break;
        }
    }
    for(Node* p = l2;p->next!=NULL;p = p->next){
        if(p->next->data == N){
            ocor2 = p->next;
            antocor2 = p;
            break;
        }
    }
    if (ocor1 == NULL || ocor2 == NULL)return;
    antocor2->next = ocor1;
    antocor1->next = ocor2;
    printf("//////////////\n");
    //lista_imprime(l1);
    printf("////////////////\n");
    //lista_imprime(l2);
    if (ocor1->next == NULL || ocor2->next == NULL)return;
    cross(ocor1->next,ocor2->next,N);
}

void cross_ite(Node* l1, Node* l2, int N){
    if(l1 == NULL || l2 == NULL)return;
    Node* ocor1 = NULL;
    Node* ocor2 = NULL;
    Node* temp2 = NULL;
    Node* temp1 = NULL;
    do{
        ocor1 = NULL;
        ocor2 = NULL;
        for(Node* p = l1;p!=NULL;p = p->next){
            if(p->data == N){
                ocor1 = p;
                break;
            }
        }
        for(Node* p = l2;p!=NULL;p = p->next){
            if(p->data == N){
                ocor2 = p;
                break;
            }
        }
        if (ocor1 == NULL || ocor2 == NULL)return;
        if(ocor1->next == NULL || ocor2->next == NULL)return;
        temp2 = ocor2->next;
        temp1 = ocor1->next;
        ocor2->next = temp1;
        ocor1->next = temp2;
        l1 = temp2;
        l2 = temp1;
    }while(l1 != NULL && l2 != NULL);
}

void misc(Node* head, int x){
    if(!head)return;
    Node* p = head;
    if(x%2 == 0){
        while(p!= NULL){
            if(p->data == x){
                p->data--;
                Node* new = malloc(sizeof(Node));
                new->data = x;
                new->next = p->next;
                p->next = new;
                for(int i = 0;i<x-1;i++){
                    Node* new2 = malloc(sizeof(Node));
                    new2->data = x-1;
                    new2->next = p->next;
                    p->next = new2;
                }
                p = new->next;
            }
            else p = p->next;
        }
    }
    else{
        while(p!=NULL){
            if(p->data == x){
                for(int i = 0;i<x;i++){
                    Node* new = malloc(sizeof(Node));
                    new->data = x+1;
                    new->next = p->next;
                    p->next = new;
                }
                p = p->next;
            }
            p = p->next;
        }
    }
}

void cross_2(Node* l1,Node* l2,int x){
    Node* ocor1 = NULL;
    Node* ocor2 = NULL;
    do{
        ocor1 = NULL;
        ocor2 = NULL;
        Node* p;
        Node* l;
        for(p = l1;p!=NULL; p = p->next){
            if(p->data == x){
                ocor1 = p;
                break;
            }
        }
        for(l = l2;l!= NULL; l = l->next){
            if(l->data == x){
                ocor2 = l;
                break;
            }
        }
        if(!ocor1 || !ocor2)return;
        Node* temp = ocor1->next;
        ocor1->next = ocor2->next;
        ocor2->next = temp;
        l1 = ocor1->next;
        l2 = ocor2->next;
    }while(1);
}

void inad(Node*head,int n){
    Node* p = head;
    Node* t = NULL;
    while(p!=NULL){
        if(p->data == n){
            t = p->next;
            for(int i = 0;i<n*2;i++){
                Node* new = (Node*)malloc(sizeof(Node));
                new->data = n;
                new->next = p->next;
                p->next = new;
            }
            p = t;
            continue;
        }
        p = p->next;
    }
}

void inad_rec(Node*head,int n){
    Node* p =head;
    if(!p)return;
    Node* t;
    if(p->data == n){
        t = p->next;
        for(int i = 0;i<n*2;i++){
            Node* new = malloc(sizeof(Node));
            new->data = n;
            new->next = p->next;
            p->next = new;
        }
        return inad_rec(t,n);
    }
    return inad_rec(p->next,n);
}

void ins_antes(Node* head, int n ){
    if(!head)return;
    Node* p = head;
    Node* t;
    while(p){
        if(p->data == n){
            t = p->next;
            for(int i = 0;i<n;i++){
                Node* new = malloc(sizeof(Node));
                new->data = n;
                new->next = p->next;
                p->next = new;
            }
            p = t;
            continue;
        }
        p = p->next;
    }
}

void ins_antes_rec(Node* head, int n ){
    if(!head)return;
    Node* p = head;
    Node* t = p->next;
    if(p->data == n){
        for(int i = 0;i<n;i++){
            Node* new = malloc(sizeof(Node));
            new->data = n;
            new->next = p->next;
            p->next = new;
        }
        return ins_antes_rec(t,n);
    }
    return(ins_antes_rec(p->next,n));

}

int miscc(Node* head){
    int pos = 0;
    Node* p = head;
    while(p!= NULL){
        if(p->data%2 != pos%2){
            return 0;
        }
        p = p->next;
        pos++;
    }
    return 1;
}
int miscc_rec(Node*head,int pos){
    Node* p = head;
    if(!p)return 1;
    if(p->data%2!= pos%2){
        return 0;
    }
    return miscc_rec(p->next,pos+1);
}
void troca(Node* head, int n1,int n2){
    Node* p = head;
    while(p){
        Node* oc1 = NULL;
        Node* oc2 = NULL;
        int ovo;
        while(p){
            if(p->data == n1 && !oc1){
                ovo = 1;
                oc1 = p;
            }
            if(p->data == n2 && !oc2){
                if(ovo) ovo = 0;
                oc2 = p;
            }
            p = p->next;
            if(oc1 && oc2)break;
        }
        if(!oc1 || !oc2)return;
        oc1->data = n2;
        oc2->data = n1;
        if(ovo) p = oc2->next;
        else p = oc1->next;
    }
}

void troca_rec(Node* head, int n1, int n2){
    Node* p = head;
    Node* oc1 = NULL;
    Node* oc2 = NULL;
    int ovo;
    while(p){
        if (p->data == n1 && oc1 == NULL){
            oc1 = p;
            ovo = 1;
        }
        if(p->data == n2 && oc2 == NULL){
            oc2 = p;
            if(ovo)ovo = 0;
        }
        p = p->next;
        if(oc1 && oc2)break;
    }
    if(!oc1 || !oc2)return;
    int temp = oc1->data;
    oc1->data = oc2->data;
    oc2->data = temp;
    if(ovo)
        return troca(oc2->next,n1,n2);
    return troca(oc1->next,n1,n2);

}

void mult_k(Node* head, int k ){
    Node* p = head;
    Node* t;
    Node* ant = NULL;
    while(p){
        if(p->data%k == 0){
            if(p->next){
                p->data = p->next->data;
                t = p->next;
                p->next = t->next;
                free(t);
                continue;
            }
            free(p);
            if(ant){
                ant->next = NULL;
                free(p);
                break;
            }
            return;
        }
        ant = p;
        p = p->next;
    }
}

void mult_k_rec(Node*head, int k){
    if(!head)return;
    Node* p = head;
    Node*t = NULL;
    if(p->data%k == 0) {
        if (p->next){
            p->data = p->next->data;
            t = p->next;
            p->next = t->next;
            free(t);
            return mult_k_rec(p,k);
        }
        return;
    }
    return mult_k_rec(p->next,k);
}

int main(){
    Node* head = NULL;
    head = insere(head,4);
    head = insere(head,4);
    head = insere(head,3);
    head = insere(head,4);
    head = insere(head,1);
    head = insere(head,4);
    /*Node* head2 =NULL;
    head2 = insere(head2,3);
    head2 = insere(head2,2);
    head2 = insere(head2,3);
    head2 = insere(head2,3);
    head2 = insere(head2,2);
    head2 = insere(head2,3);*/
    lista_imprime(head);
    printf("////////////////\n");
    mult_k_rec(head,4);
    lista_imprime(head);
    printf("////////////////\n");
    lista_exclui(head);
    return 0;
}