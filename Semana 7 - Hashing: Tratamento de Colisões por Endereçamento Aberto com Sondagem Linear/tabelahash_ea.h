#pragma once

typedef enum ESTADO {
 E_LIVRE,
 E_OCUPADO,
 E_APAGADO
} ESTADO;

typedef struct ELEM {
    int chave;
    int valor;
    ESTADO estado;
}ELEM;

typedef struct THEA{
 int m; // tamanho total
 ELEM* TH;
 int n; // quantidade total de posições ocupadas
} THEA;

int THEA_Hash(THEA* TH, int chave, int k);
THEA* THEA_Criar(int m);
int THEA_Inserir(THEA *TH, int chave, int valor);
int THEA_Buscar (THEA* TH, int chave);
int THEA_Remover(THEA *TH,int chave);

void THEA_Imprimir(THEA* TH);
int THEA_ClusterMaximo(THEA* TH);
float THEA_TamMedioClusters(THEA* TH);
float THEA_CustoBemSucedida(THEA *TH);
int* random_vector(int n, int max, int seed);
THEA* THEA_CriaRandom(int m, int n, int max, int seed);
int* tamanhos_clusters (THEA* TH, int *t);
int min(THEA* TH);
int max(THEA* TH);