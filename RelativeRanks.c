#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int esq(int ind){
    return (ind * 2 + 1);
}

int dir(int ind){
    return (ind * 2 + 2);
}

int pai(int ind){
    if(ind > 0) return (ind - 1)/2;
    return -1;
}


void min_heapfy(int* heap,int n, int ind){
    int maior = ind;
    int e = esq(ind);
    int d = dir(ind);
    if(e < n && heap[e] < heap[maior])maior = e;
    if(d < n && heap[d] < heap[maior])maior = d;
    if(maior != ind){
        int temp = heap[maior];
        heap[maior] = heap[ind];
        heap[ind] = temp;
        min_heapfy(heap,n,maior);
    }
}

void build_min_heap(int* heap, int n){
    int ult_pai = pai(n-1);
    for(;ult_pai>=0;ult_pai--){
        min_heapfy(heap,n,ult_pai);
    }
}

void heap_sort(int* heap, int n){
    build_min_heap(heap,n);
    int i;
    for(i = n-1;i>= 1;i--){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        min_heapfy(heap,i,0);
    }
}

void reverse_v(int* v, int n){
    int p1 = 0;
    int p2 = n-1;
    while(p1<p2){
        int temp = v[p1];
        v[p1] = v[p2];
        v[p2] = temp;
        p1++;
        p2--;
    }
}

int busca_ind(int* v, int x,int low, int high){
    if(high<low)return -1;
    int mid = low + (high-low)/2;
    if(v[mid] == x)return mid;
    if(v[mid]>x)return busca_ind(v,x,mid+1,high);
    else return busca_ind(v,x,low,mid-1);

}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    char** resp = malloc(sizeof(char*)*scoreSize);
    *returnSize = scoreSize;
    int copia[scoreSize];
    for(int i = 0;i<scoreSize;i++){
        copia[i] = score[i];
    }
    heap_sort(score, scoreSize);
    //reverse_v(score, scoreSize);
    char a[30];
    for(int i = 0;i<scoreSize;i++){
        int t = busca_ind(score, copia[i],0,scoreSize-1);
        if(t == 0){
            strcpy(a,"Gold Medal");
        }
        else if(t == 1){
            strcpy(a,"Silver Medal");
        }
        else if(t == 2){
            strcpy(a,"Bronze Medal");
        }
        else sprintf(a,"%d",t+1);
        resp[i] = strdup(a);
    }
    return resp;
}