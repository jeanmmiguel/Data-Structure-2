typedef struct ILISTA_NO{

    struct ILISTA_NO *prox;
    int dado;
} ILISTA_NO;

typedef struct ILISTA{

ILISTA_NO *primeiro;
ILISTA_NO *ultimo;
int tamanho;
}ILISTA;

ILISTA* ILISTA_Criar();
void ILISTA_Inserir(ILISTA *l, int dado);
int ILISTA_Tamanho(ILISTA *l);
int ILISTA_Vazia(ILISTA *l);
ILISTA_NO* ILISTA_Buscas(ILISTA *l, int dado);
int ILISTA_Remover(ILISTA *l, int dado);
void ILISTA_Imprimir(ILISTA *l);