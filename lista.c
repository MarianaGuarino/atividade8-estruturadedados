#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No *criar_no(char valor, No *proximo_no) {
    No *no = (No *) malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No *lista, No *no) {
    if (lista != NULL) {
        if (lista->proximo_no == NULL) {
            lista->proximo_no = no;
        } else {
            lista_inserir_no(lista->proximo_no, no);
        }
    }
}

void lista_imprimir(No *lista) {
    if (lista != NULL) {
        printf("%c ", lista->valor);
        lista_imprimir(lista->proximo_no);
    }
}


int lista_quantidade_no(No *lista) {
    if (lista != NULL) {
        return lista_quantidade_no(lista->proximo_no) + 1;
    }
    return 0;
}

No *copiar_lista(No *lista) {
    if (lista != NULL) {
        return criar_no(lista->valor, copiar_lista(lista->proximo_no));
    }
    return NULL;
}

void lista_concatenar(No* lista, No* listaC){
    lista_inserir_no(lista, listaC);
}

void lista_liberar(No* lista){
    if(lista != NULL){
        lista_liberar(lista->proximo_no);
        free(lista);
    }
}

int lista_verificar_existencia(No* lista, char valor_busca) {
    if (lista == NULL) 
        return 0;
    
    if (valor_busca == lista->valor) 
        return 1;
    
    return lista_verificar_existencia(lista->proximo_no, valor_busca);
}

int lista_verificar_ocorrencias(No* lista, char valor_busca) {
    int ocorrencia = 0;
    No *no_atual = lista;
    while (no_atual) {
        if (no_atual->valor == valor_busca)
            ocorrencia++;
        no_atual = no_atual->proximo_no;
    } 

    return ocorrencia;   
}

void lista_imprimir_inversa(No* lista) {
    if (lista != NULL) {
        lista_imprimir_inversa(lista->proximo_no);
        printf("%c ", lista->valor);
    }
}

void lista_inserir_no_i(No* lista, int i) {
    if (i < 0 || i > lista_quantidade_no(lista)) {
        printf("Posicao invalida para insercao.\n");
        return;
    }

    if (i == 0) {
        No* novo_no = criar_no('A', lista);
        return;
    }

    No *no_atual = lista;
    int j;
    for (j = 0; j < i - 1; ++j) {
        no_atual = no_atual->proximo_no;
    }
    No *no = criar_no('A', no_atual->proximo_no);
    no_atual->proximo_no = no;
}


void lista_remover_no_i(No* lista, int i) {
    if (i < 0) {
        printf("Posição inválida.\n");
        return;
    }

    No* atual = lista;

    if (i == 0) {
        lista = lista->proximo_no;
        free(atual);
        return;
    }

    int pos = 0;
    while (atual != NULL && pos < i - 1) {
        atual = atual->proximo_no;
        pos++;
    }

    if (atual == NULL || atual->proximo_no == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    No* no_a_remover = atual->proximo_no;
    atual->proximo_no = no_a_remover->proximo_no;
    free(no_a_remover);
}

void lista_remover_no(No* lista, char valor_busca) {
    No* atual = lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior != NULL) {
                anterior->proximo_no = atual->proximo_no;
            } else {
                lista = atual->proximo_no;
            }
            free(atual);
            atual = anterior;
        }
        anterior = atual;
        atual = atual->proximo_no;
    }
}