#include <stdbool.h>
#include <stdio.h>
#include <string.h>


bool areAlmostEqual(char* s1, char* s2) {
    if(strlen(s1)==0 )return false;
    char repeat[2];
    repeat[0] = '\0';
    int rep;
    for(int i = 0;i < strlen(s1);i++){
        if(s1[i] != s2[i]){
            if(repeat[0] == '\0'){
                repeat[0] = s1[i];
                rep = i;
            }
            else{
                if (s2[i] == repeat[0]){
                    if(s1[i] == s2[rep]){
                        char t = s1[i];
                        s1[i] = s1[rep];
                        s1[rep] = t;
                    }
                }
                else
                    return false;
            }
        }

    }
    if(!strcmp(s1,s2))
        return true;
    return false;
}