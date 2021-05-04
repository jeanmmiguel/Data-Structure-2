#include<stdio.h>
#include<stdlib.h>

void imprimir_vetor(int *v, int n);

int esquerda(int i){

 return 2 * i + 1;



}
int direita(int i){

 return 2 * i + 2;
 


}


void troca(int *v,int menor,int i){
    int aux;
    aux = v[menor];
    v[menor] = v[i];
    v[i] = aux;

}
void minHeapify(int *v,int i, int th){

 int e, d;
 int menor = i;

 e = esquerda(i);
 d = direita(i);

 if((e < th) && (v[e] < v[i]))
 menor = e;

 if((d < th) && (v[d] < v[menor]))
 menor =  d;

    if(menor != i){
        troca(v,i,menor);
       minHeapify(v,menor,th);
    }

}

void buildMinHeap(int *v, int n){

 int i ; 

    for(i = n /2 ; i >= 0;i --){
        minHeapify(v,i,n);
    }

}
void imprimir_vetor(int *v,int n){

	int i;

	for(i = 0;i<n;i++){
		printf("%d ",v[i]);
	}
	printf(" \n");
}


void minHeapSort(int* v, int n){

    int i;
    buildMinHeap(v,n);
    for(i = n -1; i > 0; i --){
        troca(v,0,i);
        minHeapify(v,0,i);
    }



}


int FP_inicio(int* fp, int n){

return fp[0];

 
    
}
int FP_remover_minimo(int* fp, int n, int *removido){
    int aux = 0;

    *removido = fp[0];
    fp[0] = fp[n];
    minHeapify(fp,0,n-1);
     n--;

    return n;


}



int FP_inserir(int* fp, int n, int x){
       
        
        fp[n] = x;
        int i = n;
        n++;
       int pai = (n-1)/2;

        while(pai >= 0 && fp[pai] > fp[i])  {
                    troca(fp,i,pai);
                    i = pai;
                    pai = (i - 1)/2;


        }    
          
 imprimir_vetor(fp,n);

         
 return n;

    
}
int main(){


    char url[]="case1.txt";
      int m, n;
      int vet[1000];
      int i = 0, k = 0, j = 0;
 FILE *arq;
 int cont = 0;
 arq = fopen(url, "r");
 int tamanho = strlen(arq);
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  for(i = 0; i <=tamanho; i++)
  fscanf(arq,"%d", &vet[i]);
  
  for(j = 0;j < 1000;j++){
      fscanf(arq,"%d",vet[j]);
  }

int fileiras = vet[0];
int pessoas = vet[1];
float preco;
buildMinHeap(vet,1000);
FP_inserir(vet,vet[0],vet[0]);
FP_inserir(vet,vet[1], vet[1]);
while(pessoas > 0){
 int e;
    FP_remover_minimo(vet,vet[1],&e);

  



}




 fclose(arq);
 
 return 0;
}












 


  
 

