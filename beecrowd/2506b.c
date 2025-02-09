#include <stdlib.h>
#include <string.h>
#include <stdio.h>



typedef struct Node{
    int hora;
    int critico;
    int atendidos;
    struct Node* next;
}Node;


Node* insere(Node* l,int data,int critico){
    Node* new = malloc(sizeof(Node));
    new->hora = data;
    new->critico = critico;
    new->next = l;
    return new;
}

Node* append(Node*l, int data, int critico,int atend){
    Node* new = malloc(sizeof(Node));
    new->hora = data;
    new->critico = critico;
    new->atendidos = atend;
    new->next = NULL;
    if (l == NULL){
        l = new;
        return l;
    }
    Node* p = l;
    while (p->next!= NULL){
        p = p->next;
    }
    p->next = new;
    return l;
}

void lista_exclui(Node*l){
    Node* p = l;
    while(p!= NULL){
        Node* t = p->next;
        free(p);
        p = t;
    }
}

void lista_imprime(Node* l){
    for(Node* p = l; p!= NULL; p = p->next){
        printf("HORA: %d CRITICO: %d ATENDIDO: %d\n",p->hora,p->critico,p->atendidos);
    }
}

int atender(Node* l,int j ){
    int atendido;
    int cont = 0;
    Node* p = l;
    for (int i = 0;i < j;i++){
        p = p->next;
    }
    //printf("ATENDIDO%d\n",p->atendidos);
    if (p->next !=NULL){
        if(p->atendidos % 30 != 0){
            atendido = 30*((p->atendidos/30)+1);
            p->atendidos = atendido;
            p->next->atendidos = atendido+30;
            if (p->atendidos>p->hora+p->critico)
                cont++;
            //printf("atendido novo:%d %d\n",j,atendido);
        }
        else p->next->atendidos = p->atendidos+30;
        //printf("atendido 2 %d\n",atendido);
        if (p->next->atendidos < p->next->hora){
            if (p->next->hora%30 != 0){
                p->next->atendidos = 30*((p->next->hora/30) +1);
            }
            else p->next->atendidos = p->next->hora;
        }
        if (p->next->atendidos - p->next->hora>p->next->critico){
            return cont+1;
        }
    }
    else{
        if(p->atendidos % 30 != 0) {
            atendido = 30 * ((p->atendidos / 30) + 1);
            p->atendidos = atendido;
            if (p->atendidos > p->hora + p->critico)
                cont++;
        }
    }
    return cont;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Node* head = NULL;
        int cont = 0;
        for (int i = 0;i<n;i++){
            int h,m,c;
            scanf("%d %d %d",&h,&m,&c);
            int hora = (h*60)+m;
            head = append(head,hora,c,hora);
        }
        //lista_imprime(head);
        for(int i = 0;i<n;i++)
            cont +=atender(head,i);
        //lista_imprime(head);
        lista_exclui(head);
        printf("%d\n",cont);
    }
}