
#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int impares[numsSize];
    int* pares = malloc(sizeof(int)*numsSize);
    int t = 0;
    int t1 = 0;
    for (int i = 0;i<numsSize;i++){
        if((nums[ i ] & 0x1 ) == 0){
            pares[t] = nums[i];
            t++;
        }
        else{
            impares[t1] = nums[i];
            t1++;
        }
    }
    for(int i = 0; i < t1;i++){
        pares[t] = impares[i];
        t++;
    }
    *returnSize = numsSize;
    return pares;
}