#include <stdio.h>
struct Person{
    char name[10];
    int age[10];
};


void updateage(struct Person *p, const int *age,const int size){
    for (int i = 0;i < size ; i++){
        p->age[i] = age[i];
        printf("%d",p->age[i]);
    }
}
int main() {
    struct Person vasco;
    int a[5]= {1,2,3,4,5};
    updateage(&vasco,a ,5);


    return 0;
}