#include <stdio.h>
#include <stdlib.h>




typedef struct {
    int dado;
    int chave;
}info;


void coutinSort(info *v, int n){

int k,i,j, temp, acumulador = 0;
int *s, *c;

k = max(v,n);
c = calloc(k + 1, sizeof(int));
s = malloc(n * sizeof(info));


for(j = 0; j < n; j++){
    c[v[j].chave]++;
}
for(i = 0; i <= k; i++){
    temp = c[i];
    c[i] = acumulador;
    acumulador+=temp;
}

for(i = 0; i <n;i++){
    s[c[v[i].chave]] = v[i];
    c[v[i].chave]++;
}

memcpy(v,s,sizeof(info)*n);
free(s);
free(c);


    
}