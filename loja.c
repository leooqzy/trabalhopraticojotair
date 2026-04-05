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
}

void imprimir(Conta *lista) {
    Conta *aux = lista;

    while (aux != NULL) {
        printf("\nID: %d", aux->id);
        printf("\nNick: %s", aux->nick);
        printf("\nNivel: %d", aux->nivel);
        printf("\nPreco: R$ %.2f\n", aux->preco);
        printf("------------------\n");

        aux = aux->prox;
    }
}

void buscar(Conta *lista) {
    int id;
    printf("Digite o ID: ");
    scanf("%d", &id);

    Conta *aux = lista;

    while (aux != NULL) {
        if (aux->id == id) {
            printf("Conta encontrada!\n");
            return;
        }
        aux = aux->prox;
    }

    printf("Conta nao encontrada!\n");
}

// Remover
void remover(Conta **lista) {
    int id;
    printf("Digite o ID para remover: ");
    scanf("%d", &id);

    Conta *aux = *lista;
    Conta *ant = NULL;

    while (aux != NULL && aux->id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Conta nao encontrada!\n");
        return;
    }

    if (ant == NULL) {
        *lista = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    free(aux);
    printf("Conta removida!\n");
}

int main() {
    Conta *lista;
    int opcao;

    inicializar(&lista);

    do {
        printf("\n1 - Inserir\n2 - Imprimir\n3 - Buscar\n4 - Remover\n0 - Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: inserir(&lista); break;
            case 2: imprimir(lista); break;
            case 3: buscar(lista); break;
            case 4: remover(&lista); break;
        }

    } while(opcao != 0);

    return 0;
}