#include <stdio.h>
#include <stdlib.h>

int esq(int ind){
    return ind*2+1;
}
int dir(int ind){
    return esq(ind)+1;
}
int pai(int ind){
    return (ind-1)/2;
}
void max_heapify(int*v , int n, int ind){
    int e = esq(ind);
    int d = dir(ind);
    int maior = ind;
    if(e < n && v[e]>v[maior])maior = e;
    if(d < n && v[d]>v[maior])maior = d;
    if(maior!= ind){
        int temp = v[maior];
        v[maior] = v[ind];
        v[ind] = temp;
        max_heapify(v, n, maior);
    }
}

void build_max_heap(int* v, int n){
    int ult_pai = pai(n-1);
    for(int i = ult_pai;i>=0;i--){
        max_heapify(v,n, i);
    }
}





int findKthLargest(int* nums, int numsSize, int k) {
    build_max_heap(nums,numsSize);
    for(int i = 0;i<k-1;i++){
        int temp = nums[0];
        nums[0] = nums[numsSize-i-1];
        nums[numsSize-i-1] = temp;
        max_heapify(nums, numsSize-i-1,0);
    }
    return nums[0];
}