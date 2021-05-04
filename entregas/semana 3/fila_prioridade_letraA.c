#include<stdio.h>
#include<stdlib.h>

void imprimir_vetor(int *v, int n);

int esquerda(int i){

 return 2 * i + 1;



}
int direita(int i){

 return 2 * i + 2;
 


}


void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}
void maxHeapify(int *v,int i, int th){

 int e, d;
 int maior = i;

 e = esquerda(i);
 d = direita(i);

 if((e < th) && (v[e] > v[i]))
 maior = e;

 if((d < th) && (v[d] > v[maior]))
 maior =  d;

    if(maior!= i){
     troca(v,i,maior);
     maxHeapify(v,maior,th);
    }

}

void buildMaxHeap(int *v, int n){

 int i ; 

    for(i = n /2; i >= 0;i --){
        maxHeapify(v,i,n);
    }
 

}
void imprimir_vetor(int *v,int n){

	int i;

	for(i = 0;i<=n;i++){
		printf("%d ",v[i]);
	}
	printf(" \n");
}


void HeapSort(int* v, int n){

    int i;
    buildMaxHeap(v,n);
    for(i = n -1; i > 0; i --){
        troca(v,0,i);
        maxHeapify(v,0,i);
    }


}


int FP_inicio(int* fp, int n){

imprimir_vetor(fp,n);
return fp[0];

 
    
}
int FP_remover_maximo(int* fp, int n, int *removido){
    int aux = 0;

    *removido = fp[0];
    fp[0] = fp[n-1];
    n--;
    maxHeapify(fp,0,n-1);

    return n;


}

//||

int FP_inserir(int* fp, int n, int x){
       
        
        fp[n] = x;
        int i = n;
        n++;
       int  pai = (n-1)/2;

        while(pai >= 0 && fp[pai] < fp[i])  {
                    troca(fp,i,pai);
                    i = pai;
                    pai = (i - 1)/2;


        }    

        
     

            
 imprimir_vetor(fp,n);

  
 return n;

    
}

int main(){

int v[100] = {10,4,0,2,3,20,0};

buildMaxHeap(v,7);

/*
buildMaxHeap(v,6);
int x = FP_inicio(v,6);
printf("Maior elemento é o %d\n",x);

int elemento = FP_remover_maximo(v,6,&elemento);
printf("elemento removido %d  ",elemento);
*/
//int insere = FP_inserir(v,4,10);
 int qtde = FP_inserir(v,7,11);

 printf("a quantidade de elementos na fila é %d", qtde);

}