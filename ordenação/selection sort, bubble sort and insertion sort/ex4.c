#include <stdio.h>
#include <stdlib.h>
/*
O algoritmo abaixo é uma modificação do algoritmo de ordenação pelo método da bolha. A idéia é
que detecte a situação que nenhuma troca ocorreu durante uma varredura, o que indica que o vetor já
está ordenado. Neste caso não é necessário realizar mais varreduras no vetor, pois já encontra-se ordenado.
Modifique e implemente o algoritmo a seguir para que a verificação de trocas inicie da forma mais tardia
possível (ou seja, de forma que nem sempre j comece em 0).
*/

void imprime_vetor();

void troca(int *v,int maior,int i){
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;


}

int bubble_sort(int* V, int n){
  int trocas;
  int j;
  int flag = 0;

  trocas = 1;
         while(trocas){
         trocas = 0;
            for(j = flag  ; j < n - 1 ; j++){
                    if(V[j] > V[j+1]){
                    troca(V,j,j+1);
                    trocas++;
                    }
            }

        }
             if(trocas == 1){
              flag = j;

         }
    imprime_vetor(V,n);

     }





void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}
void main(){

int v[] = {1,2,3,4,5,9,19,7,0};
int x = bubble_sort(v,9);

}