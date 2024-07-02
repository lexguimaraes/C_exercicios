#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Node{
    int data;
    struct Node* next;
    struct Node* ant;
}Node;


Node* insere(Node* head, int data){
    Node* new = malloc(sizeof(Node));
    new->data = data;
    new->next = head;
    if(head)head->ant = new;
    new->ant = NULL;
    return new;
}

Node* append(Node* head, int data){
    Node* new = malloc(sizeof(Node));
    if (!new)return NULL;
    new->data = data;
    new->next = NULL;
    new->ant = NULL;
    if (head ==NULL)return new;
    Node* p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = new;
    new->ant = p;
    return head;
}

void imp_reverse(Node* head){
    Node* p = head;
    if(!p)return;
    while(p->next){
        p=p->next;
    }
    for(;p!=NULL;p = p->ant){
        printf("%d\n",p->data);
    }
}
void imp_lista(Node* head){
    for(Node* p = head; p!= NULL; p = p->next){
        printf("%d\n",p->data);
    }
}

void free_lista(Node* head){
    Node* t;
    Node* p = head;
    while(p!= NULL){
        t = p->next;
        free(p);
        p = t;
    }
}


void reverse(Node* head){
    if(head == NULL)return;
    Node* p = head;
    Node* l = head;
    int temp;
    while(l->next)l = l->next;
    while(p!= l && p!=l->next){
        temp = p->data;
        p->data = l->data;
        l->data=temp;
        p = p->next;
        l = l->ant;
    }
}

Node* desloca(Node* head, int n){
    if(!head)return NULL;
    if(n%2!= 0){
        Node* antp;
        Node* ult = head;
        while(ult->next){
            antp=ult;
            ult = ult->next;
        }
        antp->next = NULL;
        ult->next = head;
        ult->ant = NULL;
        head->ant = ult;
        return ult;
    }
    Node* new_head = head->next;
    new_head->ant = NULL;
    Node* ult = head;
    while(ult->next)ult = ult->next;
    ult->next=head;
    head->next= NULL;
    return new_head;
}

Node* rto(Node* head, int n){
    if(!head)return NULL;
    Node* p = head;
    while(p!= NULL){
        if(p->data == n){
            if(p == head){
                head = head->next;
                if(!head){
                    free(p);
                    return NULL;
                }
                head->ant = NULL;
                free(p);
                p = head;
            }
            else{
                p->ant->next = p->next;
                if(p->next)p->next->ant = p->ant;
                Node* t = p;
                p = p->next;
                free(t);
            }
        }
        else p = p->next;
    }
    return head;
}
Node* i_p(Node* head){
    if(!head)return NULL;
    if(!head->next)return head;
    Node* new_head;
    for(Node* p = head;p!= NULL; p = p->next){
        if(p->data%2!=0){
            new_head = append(new_head,p->data);
        }
    }
    for(Node* p = head;p!= NULL; p = p->next){
        if(p->data%2==0){
            new_head = append(new_head,p->data);
        }
    }
    return new_head;
}

void i_p2(Node* head){
    if(!head)return;
    Node* ultp =NULL;
    int temp1;
    int temp;
    for(Node* p = head;p!= NULL;p=p->next){
        if(p->data%2!= 0){
            if(ultp){
                temp = ultp->data;
                ultp->data = p->data;
                for(Node* i = ultp->next; i!= p->next;i = i->next){
                    temp1= i->data;
                    i->data = temp;
                    temp = temp1;
                }
                ultp = ultp->next;
            }
        }
        if(!ultp){
            if(p->data%2 == 0)
                ultp=p;
        }
    }
}

Node* lista_concat(Node* l1, Node*l2){
    if (!l1)return l2;
    Node* p = l1;
    while(p->next)p = p->next;
    p->next = l2;
    l2->ant = p;
    return l1;
}

int lista_igual(Node* l1, Node*l2){
    while(l1){
        if(!l2)return 0;
        if(l1->data!=l2->data)return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l2)return 0;
    return 1;
}
int contrario(Node* l1, Node* l2){
    if(l1 == NULL || l2 == NULL)return 0;
    Node* p2 = l2;
    while(p2->next)p2=p2->next;
    for(Node* p = l1;p!= NULL; p = p->next){
        if(!p2)return 0;
        if(p->data != p2->data)return 0;
        p2 = p2->ant;
    }
    if(p2)return 0;
    return 1;
}

Node* copia(Node* head){
    if(head == NULL)return NULL;
    Node* new;
    for(Node* p = head; p!=NULL; p = p->next){
        new = append(new,p->data);
    }
    return new;

}


Node* sort_novalista(Node* head){
    if(!head)return NULL;
    if(!head->next){
        Node* new = NULL;
        new = insere(new,head->data);
        return new;
    }
    Node* new = NULL;
    for(Node* p = head; p!= NULL; p = p->next){
        new = insere(new,p->data);
    }
    if(!new)return NULL;
    int swapped;
    Node* end = NULL;
    Node* p;
    do{
        swapped = 0;
        p = new;
        while(p->next!=end){
            if(p->data>p->next->data){
                int temp = p->data;
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
        ocor1->next->ant = ocor1;
        ocor2->next->ant = ocor2;
        l1 = ocor1->next;
        l2 = ocor2->next;
    }while(ocor1 && ocor2);
}
void cross_2_rec(Node* l1,Node* l2,int x){
    if(!l1 || !l2)return;
    Node* ocor1 = NULL;
    Node* ocor2 = NULL;
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
    ocor1->next->ant = ocor1;
    ocor2->next = temp;
    temp->ant = ocor2;
    return cross_2_rec(ocor1->next,ocor2->next,x);
}
//inserir n vezes o elemento n antes e depois de cada n da lista: void
//inad(TLSE *l, int n);
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
                if (new->next)
                    new->next->ant = new;
                new->ant = p;
                p->next = new;
            }
            p = t;
            continue;
        }
        p = p->next;
    }
}


void inad_rec(Node* head, int n){
    if(!head)return;
    Node* p = head;
    Node* t = NULL;
    if(p->data == n){
        t = p->next;
        for(int i = 0;i<n*2;i++){
            Node* new = malloc(sizeof(Node));
            new->data = n;
            new->next = p->next;
            if(new->next)
                new->next->ant = new;
            new->ant = p;
            p->next = new;
        }
        return inad(t,n);
    }
    return inad(p->next,n);
}
void ins_antes(Node* head,int n){
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
                if(new->next)new->next->ant = new;
            }
            p = t;
            continue;
        }
        p = p->next;
    }
}

void ins_antes_rec(Node* head, int n){
    if(!head)return;
    Node* p = head;
    Node* t;
    if(p->data == n){
        t = p->next;
        for(int i = 0;i<n;i++){
            Node* new = malloc(sizeof(Node));
            new->data = n;
            new->next = p->next;
            p->next = new;
            if(new->next)new->next->ant = new;
        }
        return ins_antes_rec(t,n);
    }
    return ins_antes_rec(p->next,n);
}

int miscc(Node* head){
    Node* p = head;
    int pos = 0;
    while(p){
        if(p->data%2!=pos%2)
            return 0;
        p = p->next;
        pos++;
    }
    return 1;
}

int miscc_rec(Node* head, int pos){
    if(!head)return 1;
    if(head->data % 2 != pos%2){
        return 0;
    }
    return miscc_rec(head->next,pos+1);

}

void mult_k(Node* head, int k ){
    Node* p = head;
    Node* t;
    while(p){
        if(p->data%k == 0){
            if(p->next){
                p->data = p->next->data;
                t = p->next;
                p->next = t->next;
                p->next->ant = p;
                free(t);
                continue;
            }
            if(p->ant){
                p->ant->next = NULL;
                free(p);
                break;
            }
            return;
        }
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
            p->next->ant = p;
            free(t);
            return mult_k_rec(p,k);
        }
        if(p->ant){
            p->ant->next = NULL;
            free(p);
            return;
        }
        return;
    }
    return mult_k_rec(p->next,k);
}

int main(void){
    Node* head = NULL;
    head = insere(head,2);
    head = insere(head,1);
    head = insere(head,1);
    head = insere(head,1);
    head = insere(head,1231);
    head = insere(head,2);
    Node* head2 = NULL;
    head2 = insere(head2,3);
    head2 = insere(head2,2);
    head2 = insere(head2,3);
    head2 = insere(head2,3);
    head2 = insere(head2,2);
    head2 = insere(head2,3);
    mult_k_rec(head,2);
    imp_reverse(head);
    printf("///////////////////\n");
    //imp_lista(head2);
    free_lista(head);
    free_lista(head2);
    return 0;
}