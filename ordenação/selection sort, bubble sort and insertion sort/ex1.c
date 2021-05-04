#include <stdio.h>
#include <stdlib.h>
/*
 1 )Implemente a função max usada no algoritmo de ordenação por seleção apresentado no vídeo 1.
 2) Implemente a função troca usada nos algoritmos de ordenação por seleção e bolha apresentados nos vídeos
*/


void imprime_vetor();
int max();
void troca();
void selection();

int max(int *v, int inicio, int final){

int i = 0, aux = 0, maior = inicio;

for(i = inicio + 1; i <= final;i++){
    if(v[i] > v[maior]){
       maior = i;

    }
}

return maior;
}

void troca(int *v,int maior,int i){
    int aux;

    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;


}

void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void selection(int *v, int n){
    int i;
    int maior;

    for(i = n - 1; i > 0; i --){
        maior = max(v,0,i);
        troca(v,maior,i);
    }

    imprime_vetor(v,n);
}




void main(){

int x;
int v[] = {11,5,2,66,7,8};
x = max(v,0,6);
printf("maior posicao do vetor é %d\n ",x);

selection(v,6);





}