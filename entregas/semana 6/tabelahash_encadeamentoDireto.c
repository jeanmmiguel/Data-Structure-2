#include <stdlib.h>
#include <stdio.h>
#include "tabelahash_encadeamentoDireto.h"
#include "ilist.h"
#include <limits.h>
#include <time.h>

int THED_Hash(THED * TH, int chave){
  return chave % TH->M;

}

THED* TH_Criar(int m, int alloc_step ){
    THED* nova;
    int i;
    nova = malloc(sizeof(THED));
    nova->M = m;
    nova->th = malloc(sizeof(ILIST*) * m); // cada posicao é uma lista
    for(i = 0; i < m; i ++){
        nova->th[i] = ILIST_Criar(alloc_step);
    }

    return nova;
}



void THED_Inserir(THED* TH, int chave, int valor ){
     int h;
     h = THED_Hash(TH, chave);
     ILIST_Inserir(TH->th[h], chave, valor);
}

INOH* THED_Buscar(THED* TH, int chave){
  int h, pos;

  h = THED_Hash(TH, chave);
  pos = ILIST_Buscar(TH->th[h],chave);
  
  return ILIST_Endereco(TH->th[h], pos);

}
void THED_Remover(THED* TH, int chave){
  int h;
  h = THED_Hash(TH,chave);
  ILIST_Remover(TH->th[h],chave);
  
    

}
THED* inserir_n_aleatorios(int n, int m, int seed){
  
  THED* th = TH_Criar(m,10);

  int i , valor_chave;
    srand(seed);

    for(i = 0; i < n;i++){
      valor_chave = rand() % (10 * n);
      THED_Inserir(th,valor_chave,valor_chave);
    }
    return th;


}

int THED_maisCurta(THED* HT){
  int menor_tamanho = INT_MAX, i = 0;


  for(i = 0; i < HT->M;i ++){
    if(HT->th[i]->tam < menor_tamanho  && HT->th[i]->tam > 0){
      menor_tamanho = HT->th[i]->tam;
    }
  }
  return menor_tamanho;


}
 int THED_maisLonga(THED* HT){
   
     int maior_tamanho = HT->th[0]->tam,  i = 0;


  for(i = 0; i < HT->M;i ++){
    if(HT->th[i]->tam > maior_tamanho){
      maior_tamanho = HT->th[i]->tam;
    }
  }
  return maior_tamanho;


  

}

 float THED_TamMedio(THED* TH){
 int i = 0;
 float soma_tamanho = 0;

 for(i = 0; i < TH->M;i++){
   soma_tamanho += TH->th[i]->tam;
 
 }
 return soma_tamanho/TH->M;



 }

 void imprimir_THED(THED *TH){

   int i = 0, j = 0;

   for(i = 0; i < TH->M;i++){
     printf("%d ->",i);
     for(j = 0; j < TH->th[i]->max;j++){
       //if(TH->th[j]->nos[j].ocupado){
         printf("%d -",TH->th[i]->nos[j].valor);
       //}
     }
    printf("\n");

   }

}

 int min(THED* HT){

   int menor_chave = INT_MAX, i = 0;

   for(i = 0; i < HT->M;i++){
     if(menor_chave > HT->th[i]->nos->valor && HT->th[i]->tam > 0 ){
       menor_chave = HT->th[i]->nos->valor;
     }
   }
  return menor_chave;


 }
int max(THED* HT){

 int maior_chave = INT_MIN, i = 0;

 for(i = 0; i < HT->M; i ++){
   if(maior_chave < HT->th[i]->nos->valor ){
     maior_chave = HT->th[i]->nos->valor;
   }
 }
return maior_chave;



}