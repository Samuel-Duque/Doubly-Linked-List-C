#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó da pilha
struct Node {
  int value;
  struct Node *next;
};

// Função para criar um novo nó
struct Node *create_node(int value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->value = value;
  node->next = NULL;
  return node;
}

// Função para inserir um nó no topo da pilha
void push(struct Node **pilha, int value) {
  struct Node *node = create_node(value);
  node->next = *pilha;
  *pilha = node;
}

// Função para remover o nó do topo da pilha
int pop(struct Node **pilha) {
  if (*pilha == NULL) {
    return -1;
  }

  struct Node *node = *pilha;
  int value = node->value; // Salve o valor antes de liberar o nó
  *pilha = node->next;
  free(node);
  return value; // Retorne o valor salvo
}

// Função para remover um item específico da pilha
void remove_item(struct Node **pilha, int c) {
  struct Node *temp_pilha = NULL;

  // Desempilhe os itens até encontrar o item a ser removido
  while (*pilha != NULL && (*pilha)->value != c) {
    push(&temp_pilha, pop(pilha));
  }

  // Remova o item
  if (*pilha != NULL) {
    pop(pilha);
  }

  // Reempilhe os itens restantes
  while (temp_pilha != NULL) {
    push(pilha, pop(&temp_pilha));
  }
}

// Função principal
int main() {
  // Declaração da pilha
  struct Node *pilha = NULL;

  // Inserção de elementos na pilha
  push(&pilha, 10);
  push(&pilha, 5);
  push(&pilha, 2);

  // Leitura da chave do item a ser removido
  int c;
  printf("Insira a chave do item a ser removido: ");
  scanf("%d", &c);

  // Remoção do item da pilha
  remove_item(&pilha, c);

  // Impressão da pilha após a remoção
  printf("Pilha após a remoção: ");
  
    while (pilha != NULL) {
      printf("%d ", pilha->value);
      pop(&pilha);
    }
    printf("\n");

    return 0;
}
*
