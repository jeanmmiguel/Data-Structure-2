

void imprime_vetor(int *v, int n);
void troca(int *v,int maior,int i);
int partition(int *v,int p, int r);
void quickSort(int *v, int e , int d);
void merge(int *v, int p, int q, int r);
void mergeSort(int *v,int e, int d);
int* random_vector(int n, int max, int seed);
int selection();
int insertion();
int insertionSort();
int bubbleSort(int *v, int n);
int max();

int insertion(int *v, int k){

int i = k- 1;
int x = v[k];
    int count = 0;
    while((i >= 0 ) && v[i] > x){
        count++;
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = x;

    return count;

}
int insertionSort(int *v, int n){

    int j,  count = 0 ;
    for(j= 1; j < n; j++){
        count+=insertion(v,j);

    }

    return count;
}
int bubbleSort(int *v,int n){

    int i, j ;
    int cont = 0;
    for(j = n - 1; j > 0;j --){
        for(i = 0; i < j;i ++){
            if(v[i] > v[i+1]){
             troca(v,i,i + 1);
             }
         cont++;
        }
    
    }
return cont;

}
int selection(int *v, int n){
    int i;
    int maior, t = 0 ;
    int teste = 0;
    for(i = n - 1; i > 0; i --){
        maior = max(v,0,i,&t);
        troca(v,maior,i);
    }
    printf("\n");
    //imprime_vetor(v,n);
   
   return t;

}
int max(int *v, int inicio, int final, int *count){
int maior = inicio;
int i;
    for(i = inicio +1 ; i <= final; i++){
        (*count)++;
        if(v[i] > v[maior])
            maior = i;
    }
   return maior;
}



void troca(int *v,int maior,int i){
    int aux;
    aux = v[maior];
    v[maior] = v[i];
    v[i] = aux;

}

int* random_vector(int n, int max, int seed){
int *v = (int*) malloc(n * sizeof(int));
int i;
srand(seed);
    for(i = 0; i < n;i++){
        v[i] = rand() % max;
    }

mergeSort(v,0,n);
return v;
}

void imprime_vetor(int *v, int n){
    int i = 0 ;

    for(i = 0;i < n ; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

void merge(int *v, int p, int q, int r){


 int *e,*d;
 int i,j,k;
 int n1 =  q - p +1;
 int n2 = r - q;


 e = malloc(sizeof(int) * (n1 + 1));
 d = malloc(sizeof(int)*(n2 + 1));

 for(i = 0; i< n1;i++)
     e[i] = v[p + i];
     e[n1] = INT_MAX;
     for(j = 0; j < n2;j++)  
        d[j] = v[q+1+j];
         d[n2] = INT_MAX;
         i = 0;
         j = 0;
        for( k = p; k <= r ; k++){
             if(e[i] <= d[j]){
                 v[k] = e[i];
                 i++;
             }else{
                 v[k] = d[j];
                 j++;
             }
         }
     
free(e);
free(d);
}

void mergeSort(int *v,int e, int d){
    int meio;

    if(e < d){
        meio =  (e + d) / 2;
        mergeSort(v,e,meio);
        mergeSort(v,meio+1,d);
        merge(v,e,meio,d);
    }
}
int partition(int *v,int p, int r){

int x;
int i, j ;
x = v[r];
i = p - 1;

for( j = p; j < r;j++){
    if(v[j] <= x){
        i++;
        troca(v,i,j);
    }
}
troca(v,i + 1,r);
return i + 1;


}

void quickSort(int *v, int e , int d){
    int q ;

    if(e < d ){
        q = partition(v,e,d);
        quickSort(v,e,q-1);
        quickSort(v,q+1,d);


    }
}

void main(){
clock_t t;
int n = 500000;
int m = 100;
int *v = random_vector(n,n*m,0);

 t = clock();
 //int x = insertionSort(v,n);
 //int x = bubbleSort(v,n);
 //int x = selection(v,n);
 //mergeSort(v,0,n);
 quickSort(v,0,n);
 t = clock() - t; //tempo final - tempo inicial
 printf (" [%f] segundos.\n\n",((float)t)/CLOCKS_PER_SEC);





}