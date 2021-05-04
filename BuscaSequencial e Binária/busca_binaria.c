#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *v, int e, int d, int x){

    int meio;
    if( e <= d){
        meio = (e + d) / 2;
        if(v[meio] == x)
        return meio;
        else{
            if( x > v[meio]){
                return busca_binaria(v, meio +1, d , x);
            }else{
                return busca_binaria(v,e,meio - 1, x);
            }
        }
    }
    return -1;



}

void main(){

int v[] = {1,2,3,4,5,6};
int teste = busca_binaria(v,0,5,6);
if(teste == -1){
    printf("elemento não encontrado no vetor");
}else{
    printf("O elemento está na posição %d",teste);
}



}