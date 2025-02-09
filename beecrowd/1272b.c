#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char palavra[N][100];
    for (int i = 0; i < N; i++)
    {
        char letras[100] = "";
        char string[1000];
        scanf(" %[^\n]s", string);
        char *espaco = strtok(string, " ");
        while (espaco != NULL)
        {
            printf("%c",espaco[0]);
            espaco = strtok(NULL, " ");
        }
        puts("");

    }
    return 0;
}
