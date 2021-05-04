#include "lista.h"

int main(int argc, char** argv){

    ILISTA* L;
    L = ILISTA_Criar();
    ILISTA_Inserir(L,1);
    ILISTA_Inserir(L,2);
    ILISTA_Inserir(L,3);
    ILISTA_Inserir(L,1);
    ILISTA_Imprimir(L);
    ILISTA_Inserir(L,10);
    ILISTA_Inserir(L,12);
    ILISTA_Inserir(L,13);
    ILISTA_Imprimir(L);

    return 0;




}

