typedef struct No {
    char valor;
    struct No *proximo_no;
} No;

No *criar_no(char valor, No *proximo_no);
void lista_inserir_no(No *lista, No *no);
void lista_imprimir(No *lista);
int lista_quantidade_no(No *lista);
No *copiar_lista(No *lista);
void lista_concatenar(No* lista, No* listaC);
void lista_liberar(No* lista);

int lista_verificar_existencia(No* lista, char valor_busca);
int lista_verificar_ocorrencias(No* lista, char valor_busca);
void lista_imprimir_inversa(No* lista);
void lista_inserir_no_i(No* lista, int i);
void lista_remover_no_i(No* lista, int i);
void lista_remover_no(No* lista, char valor_busca);
void lista_inserir_no_ordenado(No *lista, No *no);