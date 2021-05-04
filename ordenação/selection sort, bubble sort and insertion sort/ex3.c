//Reescreva o algoritmo de ordenação por seleção apresentado no Vídeo 1 de tal forma que ordene o vetor
//escolhendo os menores elementos ao invés dos maiores.

#include <stdio.h>
#include <stdlib.h>



void imprime_vetor();
int min();
void troca();
void selection();

int min(int *v, int inicio, int final){

int i = 0, aux = 0, menor = 0;

for(i = inicio; i <= final;i++){
    if(v[i] < v[menor]){
        aux = i;
        i = menor;
        menor = aux;

    }
}

return menor;
}

void troca(int *v,int menor,int i){
    int aux;

    aux = v[menor];
    v[menor] = v[i];
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
    int menor;

    for(i = n - 1; i > 0; i --){
        menor = min(v,0,i);
        troca(v,menor,i);
    }

    imprime_vetor(v,n);
}




void main(){

int x;
int v[] = {2,5,2,66,100,200};
x = min(v,0,6);
printf("maior posicao do vetor é %d\n ",x);

selection(v,6);





}