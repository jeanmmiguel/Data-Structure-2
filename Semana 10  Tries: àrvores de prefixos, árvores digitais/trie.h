#pragma once

typedef enum ASCIITrie_Estado{ // estado do nó, indicar se o nó especifico esta guardando um  valor ou nao

    ATE_LIVRE,
    ATE_OCUPADO
} ASCIITrie_Estado;

typedef struct ASCIITrie{

 int val;
 ASCIITrie_Estado estado;
 struct ASCIITrie* filhos[256]; //256 caracteres na ascii
} ASCIITrie;

ASCIITrie* AT_Buscar(ASCIITrie* T, unsigned char* chave);
void AT_Inserir(ASCIITrie **T,unsigned char *chave, int valor);
ASCIITrie* AT_Criar();
void AT_Remover(ASCIITrie **T, unsigned char *chave);
void AT_Imprimir(ASCIITrie *T);
