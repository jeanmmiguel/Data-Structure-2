#include <stdlib.h>
#include "tabelahash_ea.h"
#include <limits.h>
#include <stdio.h>
#define Max(a, b)  (a > b) ? a : b

int THEA_Hash(THEA* TH, int chave, int k){
    return ((chave % TH->m) + k) % TH->m;
}

THEA* THEA_Criar(int m){
    THEA* novo;
    int i;

    novo = malloc(sizeof(THEA));
    novo->TH = malloc(sizeof(ELEM) * m);
    novo->m = m;
    novo->n = 0 ;

    for(i = 0; i < m; i++)
        novo->TH[i].estado = E_LIVRE;
    
     return novo;

}

int THEA_Inserir(THEA *TH, int chave, int valor){

    int h, k, h_inicial;

    k = 0;

    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

  while(TH->TH[h].estado == E_OCUPADO){

      if(TH->TH[h].chave == chave){
          break;
      }
      k++;
      h = THEA_Hash(TH, chave, k);

      if(h == h_inicial)
        return -1;
  }
  
  TH->n += TH->TH[h].chave == chave ? 0 : 1;
    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;

    return h;

}
int THEA_Buscar (THEA * TH, int chave){
  int h, h_inicial,k;
  k = 0;

  h = THEA_Hash(TH, chave,k);
  h_inicial = h;

  while(TH->TH[h].estado != E_LIVRE){
      if(TH->TH[h].estado == E_OCUPADO && TH->TH[h].chave == chave){
          return h;
      }

      k++;
      h = THEA_Hash(TH,chave, k );
       
      if(h_inicial == h){
          return -1;
      }


  }
  return -1;


}

int THEA_Remover(THEA *TH,int chave){

    int pos;

    pos = THEA_Buscar(TH, chave);
    if( pos != -1) return -1;


        TH->TH[pos].estado = E_APAGADO;
        TH->n -= 1;
        return pos;
    



}

void THEA_Imprimir(THEA* TH){

 int i;
 char estado;

 for(i = 0; i < TH->m; i ++){
     if(TH->TH[i].estado == E_OCUPADO)
     estado = 'O';

     else if(TH->TH[i].estado == E_APAGADO)
     estado = 'A';

     else 
     estado = 'L';

     printf("%d: %d , %c \n",i,TH->TH[i].chave,estado);
 }




}

int min(THEA* TH){
 int menor = INT_MAX, i ;
  
   for(i = 0; i <TH->m;i ++){
       if(TH->TH[i].estado == E_OCUPADO)
       if(TH->TH[i].valor < menor)
       menor = TH->TH[i].valor;
   }
   return menor;
 


}
int max(THEA* TH){
 int maior = INT_MIN, i ;
   
   for(i = 0; i < TH->m; i ++){
       if(TH->TH[i].estado == E_OCUPADO)
       if(TH->TH[i].valor > maior)
       maior = TH->TH[i].valor;
   }
   return maior;


}

int* random_vector(int n, int max, int seed){
  int *v = calloc(n, sizeof(int));
  srand(seed);

  for(int i = 0; i < n; i++)
    v[i] = rand() % max;

  return v;
}
int THEA_ClusterMaximo(THEA* TH){

  int maior_cluster = 0, i, cluster_atual = 0;


  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (cluster_atual > maior_cluster) {
        maior_cluster = cluster_atual;
      }

      cluster_atual = 0;
    }

    cluster_atual++;
  }

  return maior_cluster;

}

int* tamanhos_clusters (THEA* TH, int *T) {
  int i;
  int* size;
  
  *T = 0;
  size = (int*) calloc(*T+1, sizeof(int));

  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (TH->TH[i-1].estado == E_OCUPADO) {
        (*T) += 1;
        size = realloc(size, (*T+1) * sizeof(int));
        size[*T] = 0;
      }
    }else {
      size[*T] += 1;
    }
  }
  
  return size;

}

float THEA_TamMedioClusters(THEA* TH){
  int i;
  float soma_tamanho_clusters = 0;
  int qtd_clusters = 0;

  for (i = 0; i < TH->m; i++) {
    if (TH->TH[i].estado != E_OCUPADO) {
      if (TH->TH[i-1].estado == E_OCUPADO) {
        qtd_clusters++;
      }
    } else {
      soma_tamanho_clusters++;
    }
  }

  return soma_tamanho_clusters/qtd_clusters;
}

float THEA_CustoBemSucedida(THEA *TH){
int i, t;
  int* tamanho;
  float custo ;

  tamanho = tamanhos_clusters(TH, &t);
  custo= 0;

  for (i = 0; i < t; i++) {
    custo += (Max(((float)tamanho[i]/2), 1))/TH->n;
  }

  free(tamanho);

  return custo;


}