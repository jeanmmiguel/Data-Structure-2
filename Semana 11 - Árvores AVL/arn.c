#include "arn.h"
#include <stdlib.h>

static ARN* ARN_Criar(int chave, int valor){

    ARN* novo;
    novo = malloc(sizeof(ARN));
    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->esq = NULL;
    novo->dir = NULL;


    return novo;
}

static inline int eh_vermelho(ARN* A){
    if(A == NULL)
        return 0;

    return A->cor == C_VERMELHO ? 1 : 0;
}
static void inverter_cores(ARN *A){
    A->cor = C_VERMELHO;
    A->esq->cor = C_PRETO;
    A->dir->cor = C_PRETO;
}

static void rot_esq(ARN **A){
    ARN *h, *x;

    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static void rot_dir(ARN **A){
    ARN *h, *x;

    h = *A;
    x = h->esq;
    h->esq= x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}





void ARN_Inserir_R(ARN** A, int chave, int valor){
    if((*A) == NULL){
        *A = ARN_Criar(chave,valor);
    }
    if(chave < (*A)->chave){
        ARN_Inserir_R(&(*A)->esq, chave, valor);
        return ;
    }
   if(chave > (*A)->chave){
       ARN_Inserir_R(&(*A)->dir, chave, valor);
   }

   if(eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq)){
       rot_esq(A);
   }
   if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq)){
       ret_dir(A);


   }

   if(eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir)){
       inverter_cores(*A);
   }
}

void ARN_Inserir(ARN** A, int chave, int valor){

    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO;
}

void ARN_Imprimir(ARN* A, int nivel, char valor){
    int i;
    for(i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", valor);
    }
    else{
        printf("(%c) %c [%s]\n", valor, (char)A->valor, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel+1, 'e');
        ARN_Imprimir(A->dir, nivel+1, 'd');
    }
}
