#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

void free_lista(Node* head){
    Node* t;
    Node* p = head;
    do{
        t = p->next;
        free(p);
        p = t;
    }while(p!= head);
}

Node* insere(Node* head, int data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = new;
    if(head == NULL){
        return new;
    }
    new->next = head;
    Node* p = head;
    while(p->next!= head){
        p = p->next;
    }
    p->next = new;
    return new;
}

Node* insere_tail(Node* head,int data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = new;
    if(!head)return new;
    new->next = head->next;
    head->next=new;
    return new;

}
Node* append(Node* head, int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = head;
    if (!head) {
        new->next = new;
        return new;
    }
    Node *p = head;
    while (p->next != head){
        p = p->next;
    }
    p->next = new;
    return head;
}
void imprime_lista(Node* head){
    if(!head)return;
    Node* p = head;
    do{
        printf("%d\n",p->data);
        p=p->next;
    }while(p!= head);
}

Node* remove_elem(Node* head, int n){
    if(!head)return NULL;
    if(head->data == n){
        if(head->next == head){
            free(head);
            return NULL;
        }
    }
    Node* ant = NULL;
    Node* p = head;
    while(p->data!=n){
        ant = p;
        p = p->next;
    }
    if(p == head)return head;
    if(ant)
        ant->next = p->next;
    if(head->data == n){
        Node* i = head;
        while(i->next!= head){
            i = i->next;
        }
        i->next = head->next;
        head = head->next;
    }
    free(p);
    return head;
}

Node* inverte(Node* head){
    if(!head)return NULL;
    Node* new = NULL;
    Node* p = head;
    do{
        new = insere(new,p->data);
        p = p->next;
    }while(p!=head);
    return new;
}

void inverte_v(Node* head){
    if(head == NULL || head->next == NULL)return;
    Node* p = head;
    Node* ult = head;
    Node* end;
    int temp;
    while(ult->next!= head){
        ult = ult->next;
    }
    while(p != ult && (p != ult->next || p == head) ){
        temp = p->data;
        p->data= ult->data;
        ult->data = temp;
        p = p->next;
        end = ult;
        ult = head;
        while(ult->next!=end){
            ult = ult->next;
        }
    }
}

Node* desloca(Node* head, int n){
    if(n%2 == 0){
        Node* p = head;
        while(p->next!=head){
            p = p->next;
        }
        return p;
    }
    return head->next;
}

Node* copia(Node* head){
    Node* new = NULL;
    Node* p = head;
    do{
        new = append(new,p->data);
        p = p->next;
    }while(p!=head);
    return new;
}
Node* remove_oc(Node*head, int n){
    if(!head)return NULL;
    Node* temp;
    Node* p = head;
    do{
        if(p->data == n){
            if(p->next == p){
                free(p);
                return NULL;
            }
            temp = p->next;
            p->data = p->next->data;
            p->next = p->next->next;
            free(temp);
            break;
        }
        else{
            p = p->next;
        }
    }while(p!= head);
    return head;
}



Node* rto(Node* head, int n){
    Node* temp;
    if(!head)return head;
    if(head->data == n && head->next == head){
        free(head);
        return NULL;
    }
    /*if (head->data == n){
        temp = head;
        Node* p = head;
        while(p->next!=head){
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
        free(temp);
    }*/
    Node* p = head;
    int flag;
    do{
        flag = 0;
        if(p->data == n){
            if(p->next == p){
                free(p);
                return NULL;
            }
            p->data = p->next->data;
            temp = p->next;
            p->next = p->next->next;
            free(temp);
            flag = 1;
        }
        else{
            p = p->next;
        }

    }while(p!=head || flag);
    return head;
}

void i_p(Node* head){
    Node* ultp = head;
    Node* p = head;
    int temp;
    int temp1;
    do{
        if(p->data%2!= 0){
            if (ultp->data%2==0){
               temp = ultp->data;
               ultp->data = p->data;
               for(Node* i = ultp->next;i!= p->next;i = i->next){
                   temp1 = i->data;
                   i->data = temp;
                   temp = temp1;
               }
               ultp = ultp->next;
            }
        }
        else{
            if(ultp== head){
                if(head->data%2 != 0){
                    ultp = p;
                }
            }
        }
        p = p->next;
    }while(p!=head);
}


int igual(Node* l1, Node* l2){
    if(!l1 || !l2)return 0;
    Node* p = l1;
    Node* i = l2;
    while(p->next!= l1){
        if(p->data != i->data)
            return 0;
        p = p->next;
        i = i->next;
        if(i == l2){
            return 0;
        }
    }
    if(p->data!=i->data){
        return 0;
    }
    i = i->next;
    if(i!= l2)return 0;
    return 1;
}
Node* junta_listas(Node* l1, Node*l2){
    if(!l1)return l2;
    if(!l2)return l1;
    Node* p = l1;
    while(p->next!=l1){
        p = p->next;
    }
    Node* i = l2;
    while(i->next!=l2){
        i = i->next;
    }
    i->next = l1;
    p->next = l2;
    return l1;
}

int contrario(Node* l1, Node* l2){
    int cont = 0;
    Node* p = l1;
    Node* i = l2;
    int ind = 0;
    while(i->next!=l2){
        i = i->next;
        p = p->next;
        if(p == l1)return 0;
        cont++;
    }
    if(p->next!=l1)return 0;
    p = l1;
    do{
        if (p->data != i->data) {
            return 0;
        }
        p = p->next;
        i = l2;
        for (int o = 0; o < cont - ind-1; o++) {
            i = i->next;
            printf("I %d\n",i->data);
        }
        ind++;
    }while(p!=l1);
    return 1;
}
Node* sort_nova(Node* head){
    Node* new = NULL;
    Node* p = head;
    do{
        new = append(new,p->data);
        p = p->next;
    }while(p!= head);
    int swapped;
    int temp;
    Node* end = new;
    do{
        swapped = 0;
        p = new;
        while(p->next!=end){
            if(p->next->data<p->data){
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
        end = p;
    }while(swapped);
    return new;
}


int main(){
    Node* head = NULL;
    head = insere(head,15);
    head = insere(head,19);
    head = insere(head,2);
    head = insere(head,125);
    Node* head2 = sort_nova(head);
    printf("\n\n");
    imprime_lista(head2);
    free_lista(head);
    return 0;
}