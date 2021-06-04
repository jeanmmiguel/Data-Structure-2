#include<stdio.h>
#include<stdlib.h>
#include "abb.h"


ABB* ABB_Buscar(ABB *A,int chave){

   if(A == NULL)
        return NULL;

    if(A->chave == chave)
        return A;
    
    if(chave < A->chave)
        return ABB_Buscar(A->esq,chave);
    
    return ABB_Buscar(A->dir,chave);

}

ABB* ABB_Criar(int chave, ABB* esq, ABB* dir){

    ABB* novo;

    novo = malloc(sizeof(ABB));
    novo->chave = chave;
    novo->esq = esq;
    novo->dir = dir;

    return novo;

}
void ABB_Inserir(ABB **A,int chave){

    if((*A) == NULL){
        *A = ABB_Criar(chave,NULL,NULL); // como é um novo nó,aponta pra folha que é null
        return;
    }
    else{
        if(chave < (*A)->chave){
            ABB_Inserir(&(*A)->esq,chave);
        }
        else{
            ABB_Inserir(&(*A)->dir,chave);
        }
    }
}
