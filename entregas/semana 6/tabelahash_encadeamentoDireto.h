#pragma once
#include "ilist.h"

typedef struct THED{
 int M; // qtde endereços da tabela hash
 ILIST ** th;
}THED;

int THED_Hash(THED * TH, int chave);
THED* TH_Criar(int m, int alloc_step );
void THED_Inserir (THED* TH, int chave, int valor); 
INOH* THED_Buscar(THED* TH, int chave);
void THED_Remover(THED* TH, int chave);

int THED_maisCurta(THED* HT);
int THED_maisLonga(THED* HT);
float THED_TamMedio(THED* TH);
int min(THED* HT);
int max(THED* HT);
THED* inserir_n_aleatorios(int n, int m, int seed);
void imprimir_THED(THED *TH);