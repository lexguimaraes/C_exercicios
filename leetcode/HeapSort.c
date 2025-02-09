#include <stdio.h>

int pai(int ind){
    if(ind>0)return ind-1/2;
    return -1;
}

int esq(int ind){
    return ind*2+1;
}

int dir(int ind){
    return esq(ind)+1;
}

void max_heapify(int* v, int n, int ind){
    int e = esq(ind);
    int d = dir(ind);
    int maior = ind;
    if(e < n && v[e]>v[ind])maior = e;
    if(d < n && v[d]>v[maior])maior = d;
    if(maior != ind){
        int temp = v[maior];
        v[maior] = v[ind];
        v[ind] = temp;
        max_heapify(v, n, maior);
    }
}

void build_maxheap(int*v, int n){
    int ult_pai = pai(n-1);
    for(int i = ult_pai;i>=0;i--){
        max_heapify(v,n,i);
    }
}

void heap_sort(int *v, int n){
    build_maxheap(v, n);
    for(int i = n-1;i>0;i--){
        int temp = v[i];
        v[i] = v[0];
        v[0] = temp;
        max_heapify(v, i, 0);
    }
}


int* sortArray(int* nums, int numsSize, int* returnSize) {
    heap_sort(nums,numsSize);
    *returnSize = numsSize;
    return nums;
}