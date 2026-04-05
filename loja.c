#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Conta {
    int id;
    char nick[50];
    int nivel;
    float preco;
    struct Conta *prox;
} Conta;

void inicializar(Conta **lista) {
    *lista = NULL;
}

// Inserir conta
void inserir(Conta **lista) {
    Conta *novo = (Conta*) malloc(sizeof(Conta));

    printf("ID: ");
    scanf("%d", &novo->id);

    printf("Nick: ");
    scanf("%s", novo->nick);

    printf("Nivel: ");
    scanf("%d", &novo->nivel);

    printf("Preco: ");
    scanf("%f", &novo->preco);

    novo->prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        Conta *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Conta cadastrada!\n");
}

int main() {
    Conta *lista;
    int opcao;

    inicializar(&lista);

    printf("1 - Inserir conta\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        inserir(&lista);
    }

    return 0;
}