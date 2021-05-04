#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int *v, int n, int x, int p){


int pos  = -1;
int aux;

do{

pos = busca_sequencial(v, n, x, pos+1);
aux = pos;

}while(pos != -1);
 return aux;


}




void main(){

int v[] = {1,2,3,3,5,3};
int teste = busca_sequencial(v,5,3,0);
if(teste == -1){
    printf("elemento não encontrado no vetor");
}else{
    printf("O elemento está na posição %d",teste);
}



}