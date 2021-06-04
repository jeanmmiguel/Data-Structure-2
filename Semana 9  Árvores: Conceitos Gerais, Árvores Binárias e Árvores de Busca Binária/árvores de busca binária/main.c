#include <stdio.h>

#include "abb.h"

int main(int argc, char** argv){
    ABB *abb = NULL;

    ABB_Inserir(&abb, 10);
    ABB_Inserir(&abb, 4);
    ABB_Inserir(&abb, 20);
    ABB_Inserir(&abb, 6);
    ABB_Inserir(&abb, 2);
    ABB_Inserir(&abb, 3);
    
    printf("%d? %p \n", 1 , ABB_Buscar(abb,1));
    printf("%d? %p \n", 20 , ABB_Buscar(abb,20));
    printf("%d? %p \n", 5 , ABB_Buscar(abb,5));
    printf("%d? %p \n", 0 , ABB_Buscar(abb,0));
    printf("%d? %p \n", 3 , ABB_Buscar(abb,3));


    ABB_Imprimir(abb, 0 , 'r');

}