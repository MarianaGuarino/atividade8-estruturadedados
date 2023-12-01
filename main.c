#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    No* n0 = criar_no('C', NULL);
    No* n1 = criar_no('E', NULL);
    No* n2 = criar_no('A', criar_no('D', criar_no('B', criar_no('X', criar_no('Z', NULL)))));
    No* n3 = criar_no('U', NULL);
    No* n4 = criar_no('U', criar_no('U', criar_no('U', criar_no('U', criar_no('U', NULL)))));

    lista_inserir_no(n0, n2);
    lista_inserir_no(n0, n1);
    lista_inserir_no(n0, n3);
    lista_inserir_no(n0, n4);
    lista_imprimir(n0);

    lista_inserir_no_i(n0, 1);
    lista_imprimir(n0);
    return 0;
} 