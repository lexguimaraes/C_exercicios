
#include <stdio.h>
#include <stdlib.h>


typedef struct nk{
    int val;
    int freq;
}tes;

int in_v(tes* v, int n, int x){
    for(int i = 0;i<n;i++){
        if(v[i].val == x){
            v[i].freq++;
            return 1;
        }
    }
    return 0;
}

void max_heapify(tes* v, int n, int ind){
    int e = ind*2+1;
    int d = ind*2+2;
    int maior = ind;
    if(e<n && v[e].freq> v[maior].freq)maior = e;
    if(d<n && v[d].freq> v[maior].freq)maior = d;
    if(maior!=ind){
        tes temp = v[maior];
        v[maior] = v[ind];
        v[ind] = temp;
        max_heapify(v,n,maior);
    }
}

void build_max_heap(tes*v, int n){
    int ult_pai = (n-2)/2;
    for(int i = ult_pai;i>=0;i--){
        max_heapify(v,n,i);
    }
}







int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* resp = malloc(sizeof(int)*k);
    *returnSize = k;
    if(k == 0)return resp;
    if(numsSize == 1){
        resp[0] = nums[0];
        return resp;
    }
    tes* heap = malloc(sizeof(tes)*numsSize);
    int n = 0;
    for(int i = 0;i<numsSize;i++){
        if(!in_v(heap,n,nums[i])){
            heap[n].val = nums[i];
            heap[n].freq=1;
            n++;
        }
    }
    build_max_heap(heap,n);
    int rt = 0;
    for(int i = 0;i<k;i++){
        resp[rt] = heap[0].val;
        //tes temp = heap[0];
        heap[0] = heap[n-i-1];
        //heap[n-i-1] = temp;
        rt++;
        max_heapify(heap,n-i-1,0);
    }
    free(heap);
    return resp;
}