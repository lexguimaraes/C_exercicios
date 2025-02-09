#include <stdio.h>
#include <math.h>

int maxArea(int* height, int heightSize) {
    int a = 0;
    int p1 = 0;
    int p2 = heightSize-1;
    int m;
    while(p1<p2){
        m = p1;
        if (height[m] > height[p2]) m = p2;
        if(a<height[m]*(p2-p1)){
            a = height[m]*(p2-p1);
        }
        if(height[p1] < height[p2])p1++;
        else p2--;
    }
    return a;
}

int main(void){
    int height[] = {1,8,6,2,5,4,8,3,7};
    int t = maxArea(height,9);
    printf("%d", t);
    return 0;
}