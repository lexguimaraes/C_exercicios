#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char str[], int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    int n, d;
    char palavra[100001];
    int cont = 0;
    int cont1 = 0;
    for (;;) {
        scanf("%d %d", &n, &d);
        if ((n == 0) && (d == 0)) {
            break;
        }
        scanf("%s", palavra);
        cont = 0;
        for (int j = 1; j <= d; j++){
            if ((n/j)*j<cont)
                break;
            for (int ind = 0; ind <= n - j; ind += d) {
                if (isPalindrome(palavra, ind, ind + j - 1)) {
                    cont1 += j;
                }
            }
            if (cont1 > cont)
                cont = cont1;
            cont1=0;
        }
        printf("%d\n", cont);
    }
    return 0;
}