#include <stdio.h>

#include "trie.h"

int main(int argc, char** argv){
    ASCIITrie *T = NULL;

    AT_Inserir(&T, "", 42);
    AT_Inserir(&T, "o", 1);
    AT_Inserir(&T, "rato", 10);
    AT_Inserir(&T, "roeu", 11);
    AT_Inserir(&T, "a", 2);
    AT_Inserir(&T, "roupa", 12);
    AT_Inserir(&T, "do", 3);
    AT_Inserir(&T, "rei", 13);
    AT_Inserir(&T, "de", 14);
    AT_Inserir(&T, "", 42);
    AT_Inserir(&T, "roma", 15);


    AT_Imprimir(T);

    ASCIITrie* r;

    r = AT_Buscar(T, "");
    r;

     r = AT_Buscar(T, "rato");
     r;

     r = AT_Buscar(T, "roeu");
     r;
    
     r = AT_Buscar(T, "roam");
     r;



}