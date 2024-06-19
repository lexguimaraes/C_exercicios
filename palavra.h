

typedef struct Palavra{
    char palavra[51];
    char categoria[16];
    double vetor[50];
}palavra;



palavra* palavra_cria(const char* categoria, const double* vetor,const char*palavra1);

void palavra_libera(palavra* palavra1);

double cosin(palavra* palavra1,palavra* palavra2,int size);

double dist_euclid(palavra* palavra1,palavra* palavra2,int size);

double normavetor(palavra* palavra1,int size);

double multvetor(palavra* palavra1,palavra* palavra2,int size);

int norma_compara(palavra* palavra1,palavra* palavra2,int size);

int palavra_compara(palavra* palavra1,palavra* palavra2);
