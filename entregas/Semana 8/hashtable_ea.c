#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"
#include "prime_list.h"
#include <limits.h>
#include <math.h>

#define Max(a, b)  (a > b) ? a : b

static void  THEA_Redimensionar(THEA* TH, int m_novo){
    ELEM  *nova, *antiga; // ponteiro para a nova tabela e uma para a tabela velha
    int i, m_antigo;
    int m_primo;

    if(m_novo <= 15485863 ){
     m_novo =  PL_NextPrime(TH->prime_list, m_novo);

    }

    nova = malloc(sizeof(ELEM) * m_novo);
    for(i = 0; i < m_novo;i ++){
        nova[i].estado = E_LIVRE;
    }
    antiga = TH->TH;
    m_antigo = TH->m;
    TH->TH = nova;
    TH->m = m_novo;
    TH->n = 0;
    TH->colisoes = 0;

    for(i = 0; i < m_antigo; i++){
        if(antiga[i].estado == E_OCUPADO){
            THEA_Inserir(TH,antiga[i].chave, antiga[i].valor);
        }
    }

    free(antiga);

}

int THEA_Hash(THEA* TH, int chave, int k){
   if(TH->probing == P_LINEAR){
     return probing_linear(TH,chave,k);
   }else if (TH->probing == P_QUADRATICA){
     return probing_quadratica(TH,chave,k);
   }else if (TH->probing == P_DUPLA ){
     return probing_dupla(TH,chave,k);
   }


}
int probing_linear(THEA* TH,int chave, int k){
  return ((chave % TH->m) + k) % TH->m;
}
int probing_quadratica(THEA* TH, int chave, int k){
  return ((chave % TH->m) + k*k) % TH->m;
}
int probing_dupla(THEA* TH, int chave, int k){
return ((chave % TH->m) + k* ((chave % (TH->m - 1))+1)) % TH->m;
}

THEA* THEA_Criar(int m, PROBING_TYPE probing){
    THEA* novo;
    prime_list_t*  lista_primo;
    int m_primo,i;
    
    lista_primo = PL_Load("primes1.dat",1000000);

    m_primo = PL_NextPrime(lista_primo,m);
    novo = malloc(sizeof(THEA));
    novo->TH = malloc(sizeof(ELEM) * m_primo);
    novo->m = m_primo;
    novo->n = 0 ;
    novo->prime_list = lista_primo;
    novo->colisoes = 0;

    for(i = 0; i < m; i++){ 
        novo->TH[i].estado = E_LIVRE;
    }
    novo->probing = probing;
   
     return novo;

}

int THEA_Inserir(THEA *TH, int chave, int valor){

    int h, k, h_inicial;
    k = 0;

    if(TH->n > TH->m / 2){
        printf("redimensionada de %d para %d n = %d\n",TH->m, TH->m*2, TH->n);
        THEA_Redimensionar(TH,TH->m * 2);
    }

    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

  while(TH->TH[h].estado == E_OCUPADO){
      TH->colisoes++;
      if(TH->TH[h].chave == chave){
          TH->n--;
          break;
      }
      k++;
      h = THEA_Hash(TH, chave, k);

      if(h == h_inicial)
        return -1;
  }
  
    TH->n++;
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
        TH->n--;
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


int* random_vector(int n, int max, int seed){
  int *v = calloc(n, sizeof(int));
  srand(seed);

  for(int i = 0; i < n; i++){ 
    v[i] = rand() % max;
  }

  return v;
}
THEA* THEA_Random(int m, int n, int max, int seed, PROBING_TYPE probing){
  THEA* TH = THEA_Criar(m, probing);
  int *chave = random_vector(n, max, seed);

  for(int i = 0; i < n; i++){
    THEA_Inserir(TH, chave[i], chave[i]);
  }

  return TH;
}