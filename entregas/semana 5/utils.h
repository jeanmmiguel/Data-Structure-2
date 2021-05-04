#pragma once

void imprime_vetor(int *v, int n);
void troca(int *v,int menor,int i);
int esquerda(int i);
int direita(int i);
int max(int *v, int inicio, int final);
int SelectionMinK(int *v, int n, int k);
int HeapMinK(int *v, int n, int k);
void minHeapify(int *v,int i, int th);
void buildMinHeap(int *v, int n);
int partition(int *v,int p, int r);
int QuickMinK(int *v, int e, int d, int k);
void embaralhar(int *v, int ini, int fim);
int* random_vector_unique_elems(int n, int seed);

