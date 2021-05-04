#pragma once
#include "prime_list.h"

typedef enum ESTADO {
 E_LIVRE,
 E_OCUPADO,
 E_APAGADO
} ESTADO;

typedef enum PROBING_TYPE{
 P_LINEAR,
 P_QUADRATICA,
 P_DUPLA
 }PROBING_TYPE;

typedef struct ELEM {
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA{
 int m; // tamanho total
 ELEM* TH;
 int n; // quantidade total de posições ocupadas
 prime_list_t* prime_list; 
 int colisoes;
PROBING_TYPE probing;
}THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m, PROBING_TYPE probing);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar (THEA* TH, int chave);
int THEA_Remover(THEA *TH,int chave);
int THEA_Hash(THEA* TH, int chave, int k);
void THEA_Imprimir(THEA* TH);
int* random_vector(int n, int max, int seed);
THEA* THEA_Random(int m, int n, int max, int seed, PROBING_TYPE probing);
int probing_linear(THEA* TH,int chave, int k);
int probing_quadratica(THEA* TH, int chave, int k);
int probing_dupla(THEA* TH, int chave, int k);