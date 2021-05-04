#include <stdio.h>
#include<stdlib.h>

/*
Considere que a entrada para o algoritmo de ordenação por inserção apresentado no vídeo 3 seja um vetor
v de tamanho n tal que todos os elementos são iguais. Quantas vezes o laço while vai executar? Explique seu
raciocínio.
R: Nenhuma vez,pois na condição do while -  while((i >= 0 ) && v[i] > x) - já nem entra pois v[0] = valor e valor não é > valor,pois são iguais, então falha
nessa condição;



Considere que a entrada para o algoritmo de ordenação por inserção apresentado no vídeo 3 seja um vetor
v de tamanho n tal que os elementos estejam ordenados em ordem decrescente. Quantas vezes o laço while
vai executar? Explique seu raciocínio.
R: Nenhuma,pois é verificada a condição, entra no while mas quando decrementa o i ele passa a valer -1, depois v[i + 1 ] = x sendo que x
é o segundo maior valor;
ex: 10,9,8,7
int i = k- 1; // i aqui vale 0
int count = 0;
int x = v[k]; // x aqui vale 9


while((i >= 0 ) && v[i] > x){ // 0 é igual a zero? sim, v[0] = 10 > 9? sim então entra no while após a condição verificada
         count ++;

         v[i + 1] = v[i]; // v[1] = 9 vai receber v[0] = 10 // 10,10,9,8,7
           i--; // i vale -1, agora quando for verificar de novo, não entra no while e v[-1 +1] = v[0] = 9
  }
   v[i + 1] = x;

*/




void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int insertion(int *v, int k){

int i = k- 1;
int count = 0;

int x = v[k];

    while((i >= 0 ) && v[i] > x){
         count ++;

         v[i + 1] = v[i];
           i--;
  }
   v[i + 1] = x;


return count;
}
void insertionSort(int *v, int n){

    int j;

    for(j= 1; j < n; j++){
        insertion(v,j);

    }

    imprime_vetor(v,7);

}




void main(){

int v[] = {1,9,8,2,0,4,2};
int x = insertion(v,7);
insertionSort(v,7);
printf("%d vezes",x);




}