#include <stdio.h>
#include <stdlib.h>

// Estrutura da conta
typedef struct Conta {
    int id;
    char nick[50];
    int nivel;
    float preco;
    struct Conta *prox;
} Conta;

// Inicializar lista
void inicializar(Conta **lista) {
    *lista = NULL;
}

int main() {
    Conta *lista;

    inicializar(&lista);

    printf("Lista inicializada com sucesso!\n");

    return 0;
}