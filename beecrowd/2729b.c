#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char palavra[50];
    struct Node* next;
}Node;

Node* insere(Node* l, char* data){
    Node* new = malloc(sizeof(Node));
    strcpy(new->palavra,data);
    new->next = l;
    return new;
}

void sort(Node* head){
    if (head == NULL)return;
    Node* temp;
    for(Node* p = head;p!= NULL;p = p->next){
        temp = p;
        for (Node* i = p->next;i!=NULL;i = i->next){
            //printf("PALAVRA PIVO: %s PALAVRA i: %s\n",pivo,i->palavra);
            if(strcmp(i->palavra,temp->palavra)<0){ // NOLINT(*-suspicious-string-compare)
                temp = i;
            }
        }
        if (temp!=p){
            char palavratmp[50];
            strcpy(palavratmp,p->palavra);
            strcpy(p->palavra,temp->palavra);
            strcpy(temp->palavra,palavratmp);
        }
    }


}

int repeat(Node*l,char* data){
    for(Node* p = l; p!= NULL; p = p->next){
        if (strcmp(p->palavra,data)==0){
            return 1;
        }
    }
    return 0;
}
void imprime_lista(Node* head){
    for(Node* p = head;p!=NULL; p = p->next){
        printf("%s",p->palavra);
        if (p->next!=NULL){
            printf(" ");
        }
    }
    printf("\n");
}

void exclui_lista(Node*head){
    Node*t;
    Node* p =head;
    while (p!=NULL){
        t = p->next;
        free(p);
        p = t;
    }
}

int main(){
    Node* head = NULL;
    int n;
    char palavra[20001];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        memset(palavra,0,sizeof(palavra));
        head = NULL;
        scanf(" %[^\n]",palavra);
        char* token;
        token = strtok(palavra," ");

        while (token!=NULL){
            //printf("%s",token);
            if (repeat(head, token)==0)
                head = insere(head,token);
            token = strtok(NULL, " ");
        }
        //imprime_lista(head);
        sort(head);
        imprime_lista(head);
        exclui_lista(head);
    }


    return 0;
}