#pragma once
typedef enum {
    C_VERMELHO,
    C_PRETO
} ARN_COR;


typedef struct ARN{
    struct ARN *esq;
    struct ARN *dir;
    int chave;
    int valor;
    ARN_COR cor;
} ARN;

//ARN* ARN_Criar(int dado);
void ARN_Inserir(ARN** A, int chave, int valor);
void ARN_Imprimir(ARN* A, int nivel, char valor);