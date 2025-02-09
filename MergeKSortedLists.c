#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void min_heapify(int* v, int n, int ind){
    int e = ind*2+1;
    int d = e+1;
    int maior = ind;
    if(e<n && v[e]<v[maior])maior = e;
    if(d<n && v[d]<v[maior])maior = d;
    if(maior!= ind){
        int temp = v[maior];
        v[maior] = v[ind];
        v[ind] = temp;
        min_heapify(v,n,maior);
    }
}

void build_min_heap(int* v, int n){
    int ult_pai = (n-2)/2;
    for(int i = ult_pai;i>= 0;i--){
        min_heapify(v,n,i);
    }
}

void heap_sort(int*v, int n){
    build_min_heap(v,n);
    for(int i = n-1;i>=1;i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        min_heapify(v,i,0);
    }
}

struct ListNode* insere(struct ListNode* l, int val){
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->next = l;
    new->val = val;
    return new;
}



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* resp = NULL;
    int capacity = 10;
    int size = 0;
    int* heap = malloc(sizeof(int)*capacity);
    for(int i = 0;i<listsSize;i++){
        for(struct ListNode* p = lists[i];p!=NULL;p= p->next){
            if(size>= capacity){
                capacity *=2;
                heap = realloc(heap, sizeof(int)*capacity);
            }
            heap[size] = p->val;
            size++;
        }
    }
    heap_sort(heap,size);
    for(int i = 0;i<size;i++){
        resp = insere(resp, heap[i]);
    }
    free(heap);
    return resp;
}