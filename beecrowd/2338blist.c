#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void morse(char *tmp){
    if(strcmp( tmp, "=.===") == 0) printf("a");
    else if(strcmp( tmp, "===.=.=.=") == 0) printf("b");
    else if(strcmp( tmp, "===.=.===.=") == 0) printf("c");
    else if(strcmp( tmp, "===.=.=") == 0) printf("d");
    else if(strcmp( tmp, "=") == 0) printf("e");
    else if(strcmp( tmp, "=.=.===.=") == 0) printf("f");
    else if(strcmp( tmp, "===.===.=") == 0) printf("g");
    else if(strcmp( tmp, "=.=.=.=") == 0) printf("h");
    else if(strcmp( tmp, "=.=") == 0) printf("i");
    else if(strcmp( tmp, "=.===.===.===") == 0) printf("j");
    else if(strcmp( tmp, "===.=.===") == 0) printf("k");
    else if(strcmp( tmp, "=.===.=.=") == 0) printf("l");
    else if(strcmp( tmp, "===.===") == 0) printf("m");
    else if(strcmp( tmp, "===.=") == 0) printf("n");
    else if(strcmp( tmp, "===.===.===") == 0) printf("o");
    else if(strcmp( tmp, "=.===.===.=") == 0) printf("p");
    else if(strcmp( tmp, "===.===.=.===") == 0) printf("q");
    else if(strcmp( tmp, "=.===.=") == 0) printf("r");
    else if(strcmp( tmp, "=.=.=") == 0) printf("s");
    else if(strcmp( tmp, "===") == 0) printf("t");
    else if(strcmp( tmp, "=.=.===") == 0) printf("u");
    else if(strcmp( tmp, "=.=.=.===") == 0) printf("v");
    else if(strcmp( tmp, "=.===.===") == 0) printf("w");
    else if(strcmp( tmp, "===.=.=.===") == 0) printf("x");
    else if(strcmp( tmp, "===.=.===.===") == 0) printf("y");
    else if(strcmp( tmp, "===.===.=.=") == 0) printf("z");

}


typedef struct Node{
    char simbolos[1001];
    struct Node * next;
}Node;


Node* insere(Node* l, char* data){
    Node *new = (Node*)malloc(sizeof(Node));
    strcpy(new->simbolos,data);
    new->next=l;
    return new;
}

void reverse(Node** head) {
    Node *ant = NULL;
    Node *atual = *head;
    Node *next = NULL;
    while (atual != NULL) {
        next = atual->next;
        atual->next = ant;
        ant = atual;
        atual = next;

    }
    (*head)= ant;
}

Node* append(Node* head,char* data){
    Node* new = malloc(sizeof(Node));
    strcpy(new->simbolos,data);
    new->next = NULL;
    if (head == NULL){
        head = new;
        return head;
    }
    Node* p;
    for(p = head; p->next!=NULL;p = p->next);
    p->next = new;
    return head;
}

void imprime(Node* l){
    char* token;
    char* str;
    for(Node* p = l;p!=NULL;p=p->next){
        if(p != l)
            printf(" ");
        str = p->simbolos;
        do {
            token = strstr(str,"...");
            if (token)
                *token='\0';
            morse(str);
            if (token)
                str = token+3;
        } while(token!=NULL);

    }
    printf("\n");
}

void exclui_lista(Node* head){
    Node* p = head;
    Node* t;
    while(p){
        t = p->next;
        free(p);
        p=t;
    }
}


int main(){
    char frase[1001];
    int n;
    scanf("%d",&n);
    Node * head = NULL;
    for (int i = 0;i<n;i++){
        head = NULL;
        memset(frase,0,sizeof(frase));
        scanf(" %[^\n]",frase);
        char* str = frase;
        char* token;
        do{
            token = strstr(str,".......");
            if (token!=NULL){
                *token = '\0';
            }
            head = append(head,str);
            //printf("%s",head->simbolos);
            if(token)
                str = token+7;
        }while(token!=NULL);
        //reverse(&head);
        imprime(head);
        exclui_lista(head);
    }
    return 0;
}


