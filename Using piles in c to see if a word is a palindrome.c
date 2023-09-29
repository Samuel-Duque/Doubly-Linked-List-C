#include <stdio.h>
#include <stdlib.h>

struct no {
  char caracter;
  struct no *proximo;
};

struct no *novo_no(char caracter) {
  struct no *no = (struct no *)malloc(sizeof(struct no));
  no->caracter = caracter;
  no->proximo = NULL;
  return no;
}

void empilhar(struct no **pilha, char caracter) {
  struct no *no = novo_no(caracter);
  no->proximo = *pilha;
  *pilha = no;
}

char desempilhar(struct no **pilha) {
  if (*pilha == NULL) {
    return '\0';
  }

  struct no *no = *pilha;
  *pilha = no->proximo;
  char caracter = no->caracter;
  free(no);
  return caracter;
}

int eh_palindromo(char *texto) {
  struct no *pilha = NULL;

  for (int i = 0; texto[i] != '\0'; i++) {
    if (texto[i] != ' ') {
      empilhar(&pilha, texto[i]);
    }
  }

  for (int i = strlen(texto) - 1; i >= 0; i--) {
    if (texto[i] != desempilhar(&pilha)) {
      return 0;
    }
  }

  return 1;
}

int main() {
  char texto[100];

  printf("Digite uma sequência de caracteres: ");
  fgets(texto, 100, stdin);

  if (eh_palindromo(texto)) {
    printf("A sequência é um palíndromo.\n");
  } else {
    printf("A sequência não é um palíndromo.\n");
  }

  return 0;
}

