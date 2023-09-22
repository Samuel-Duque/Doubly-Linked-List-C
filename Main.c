#include <stdio.h>
#include <stdlib.h>

struct No{
    int celula;
    struct No* prox;
    struct No* antes;
};

struct No *criarNo(int celula){
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->celula = celula;
    novoNo->prox = NULL;
    novoNo->antes = NULL;
    return novoNo;
};

int main()
{
    struct No* primeiroNo = criarNo(1);
    struct No* segundoNo = criarNo(2);
    struct No* terceiroNo = criarNo(3);
    
    primeiroNo->prox = segundoNo;
    segundoNo->antes = primeiroNo;
    segundoNo->prox = terceiroNo;
    terceiroNo->antes = segundoNo;
    
    struct No* NoAtual = primeiroNo;
    while(NoAtual != NULL){
        printf("%d", NoAtual->celula);
        NoAtual = NoAtual->prox;
    }
    free(primeiroNo);
    free(segundoNo);
    free(terceiroNo);
    
    
    
    return 0;
}

