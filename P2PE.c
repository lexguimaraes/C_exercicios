#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

typedef struct Aminoacido{
    char nome[20];
    int polaridade;
    int essencialidade;
    float massa;
}AminoA;

typedef struct Node{
    AminoA* data;
    struct Node* next;
}Cadeia;

AminoA* criaamino(char* nome, int polaridade, int essencialidade, float massa){
    AminoA* new = malloc(sizeof(AminoA));
    strcpy(new->nome,nome);
    new->polaridade = polaridade;
    new->essencialidade = essencialidade;
    new->massa = massa;
    return new;
}

void libera_amino(AminoA* am){
    free(am);
}

Cadeia* inicializacadeia(Cadeia* l){
    return NULL;
}

void libera_cadeia(Cadeia* l ){
    Cadeia* aux = l;
    Cadeia* t;
    while(aux){
        t = aux->next;
        free(aux->data);
        free(aux);
        aux = t;
    }
}

int eh_proteina_rec(Cadeia* l, float massa){
    if(massa > 10000)return 1;
    if(!l)return 0;
    return eh_proteina_rec(l->next,massa+l->data->massa);
}

int eh_proteina(Cadeia* l){
    return eh_proteina_rec(l, 0);
}


//questão 4;

void sort(Cadeia* l){
    int swapped = 0;
    Cadeia* end = NULL;
    do{
        Cadeia* p = l;
        swapped = 0;
        while(p->next!= end){
            if(p->next->data->massa < p->data->massa){
                AminoA* t;
                t = p->next->data;
                p->next->data = p->data;
                p->data = t;
                swapped = 1;
            }
            p = p->next;
        }
        end = p;
    }while(swapped);
}



Cadeia* transformar_proteina(Cadeia* l){
    if(!l)return NULL;
    while(eh_proteina(l)){
        Cadeia* p = l;
        Cadeia* ant = NULL;
        Cadeia* antoficial = NULL;
        float min = FLT_MAX;
        Cadeia* menor = NULL;
        while(p){
            if(p->data->massa < min){
                antoficial = ant;
                menor = p;
                min = p->data->massa;
            }
            ant = p;
            p = p->next;
        }
        if(antoficial){
            antoficial->next = menor->next;
            free(menor->data);
            free(menor);
        }
        else{
            Cadeia* t = l;
            l = l->next;
            free(t->data);
            free(t);
        }
    }
    return l;
}

Cadeia* adicionar_nao_essencial(Cadeia* l1, Cadeia* l2){
    Cadeia* p1 = l1;
    Cadeia* p2= l2;
    for(;p2!= NULL;p2 = p2->next){
        if(p2->data->essencialidade == 0)break;
    }
    if(!p2)return l1;
    for(;p1!= NULL; p1 = p1->next){
        if(p1->data->polaridade==0)break;
    }
    if(!p1){
        l1 = insere(l1, p2->data);
        return l1;
    }
    Cadeia* new = malloc(sizeof(Cadeia));
    new->data = criaamino(p2->data->nome,p2->data->polaridade, p2->data->essencialidade,p2->data->massa);
    new->next = p1->next;
    p1->next = new;
    return l1;
}
