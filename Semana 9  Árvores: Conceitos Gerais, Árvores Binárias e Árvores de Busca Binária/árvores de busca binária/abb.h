#pragma once

typedef struct ABB{
    struct ABB* esq;
    struct ABB* dir;
    int chave;
} ABB;

ABB* ABB_Buscar(ABB *A, int chave);
ABB* ABB_Criar(int chave, ABB* esq, ABB* dir);
void ABB_Inserir(ABB **A,int chave);