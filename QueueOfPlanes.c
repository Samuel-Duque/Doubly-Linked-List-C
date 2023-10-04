#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar as informações do avião
typedef struct {
    int id;
    char nome[50];
    // Adicione mais características conforme necessário
} Aviao;

// Estrutura do nó da fila
typedef struct No {
    Aviao aviao;
    struct No* prox;
} No;

// Função para criar um novo nó
No* criar_no(Aviao aviao) {
    No* no = (No*) malloc(sizeof(No));
    no->aviao = aviao;
    no->prox = NULL;
    return no;
}

// Função para adicionar um avião à fila de espera
void adicionar_aviao(No** inicio, Aviao aviao) {
    No* no = criar_no(aviao);
    if (*inicio == NULL) {
        *inicio = no;
    } else {
        No* atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = no;
    }
}

// Função para autorizar a decolagem do primeiro avião da fila
void autorizar_decolagem(No** inicio) {
    if (*inicio == NULL) {
        printf("Não há aviões na fila de decolagem.\n");
        return;
    }
    No* temp = *inicio;
    *inicio = (*inicio)->prox;
    printf("Avião %s (ID: %d) autorizado para decolar.\n", temp->aviao.nome, temp->aviao.id);
    free(temp);
}

// Função para listar todos os aviões na fila de espera
void listar_avioes(No* inicio) {
    if (inicio == NULL) {
        printf("Não há aviões na fila de decolagem.\n");
        return;
    }
    No* atual = inicio;
    while (atual != NULL) {
        printf("Avião: %s, ID: %d\n", atual->aviao.nome, atual->aviao.id);
        atual = atual->prox;
    }
}

// Função para listar as características do primeiro avião da fila
void listar_primeiro_aviao(No* inicio) {
    if (inicio == NULL) {
        printf("Não há aviões na fila de decolagem.\n");
        return;
    }
    printf("Primeiro avião na fila: %s, ID: %d\n", inicio->aviao.nome, inicio->aviao.id);
}

// Função principal
int main() {
    No* inicio = NULL;

    // Adicione alguns aviões à fila para teste
    Aviao a1 = {1, "Avião 1"};
    Aviao a2 = {2, "Avião 2"};
    Aviao a3 = {3, "Avião 3"};
    
    adicionar_aviao(&inicio, a1);
    adicionar_aviao(&inicio, a2);
    adicionar_aviao(&inicio, a3);

    // Teste as funções
    listar_avioes(inicio);
    
    autorizar_decolagem(&inicio);
    
    listar_avioes(inicio);

    return 0;
}
