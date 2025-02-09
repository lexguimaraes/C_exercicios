#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* insere(struct ListNode* head, int x){
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = x;
    new->next = head;
    return new;
}



struct ListNode* mergeNodes(struct ListNode* head) {
    int num = 0;
    int t1 = 1;
    struct ListNode* resp = NULL;
    int s = 0;
    int capacity = 10;
    int* res = malloc(sizeof(int)*capacity);
    for(struct ListNode* p = head;p;p = p->next){
        if (p->val == 0)
            t1++;
        num+=p->val;
        if(t1>= 2){
            if(num>0){
                if(s+1>capacity){
                    capacity*=2;
                    res = realloc(res,sizeof(int)*capacity);
                }
                res[s] = num;
                s++;
            }
            t1 = 1;
            num = 0;
        }
    }
    for(int i = s-1;i >=0;i--){
        resp = insere(resp, res[i]);
    }
    free(res);
    return resp;
}