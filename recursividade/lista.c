#include "lista.h"
#include <stdlib.h>
#include<stdio.h>

ILISTA* ILISTA_Criar(){

ILISTA* novo;
novo = (ILISTA*) malloc(sizeof(ILISTA));
novo->primeiro = NULL;
novo->ultimo =  NULL;
novo->tamanho = 0;

return novo; 
}

void ILISTA_Inserir(ILISTA *l, int dado){

ILISTA_NO *novo;

novo = malloc(sizeof(ILISTA_NO));
novo->dado = dado;
novo->prox = novo;

if((ILISTA_Vazia(l))){
    l->primeiro = novo;
    l->ultimo = novo;

}else{
    l->ultimo->prox = novo;
    l->ultimo = novo;
}
l->tamanho++;

}


int ILISTA_Tamanho(ILISTA *l){
    return l->tamanho;
}
int ILISTA_Vazia(ILISTA *l){
    return l->tamanho == 0 ? 1: 0 ;


}

ILISTA_NO* ILISTA_Buscas(ILISTA *l, int dado);
int ILISTA_Remover(ILISTA *l, int dado);


void ILISTA_Imprimir(ILISTA *l){

    ILISTA_NO* n;

    for(n = l->primeiro; n != NULL; n = n->prox){
        printf("%d, ",n->dado);
    }
    printf("\n");




}