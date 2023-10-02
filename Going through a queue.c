#include <stdio.h>
#include <stdlib.h>

//novo means new | no means node

typedef struct no{
    int num;
    struct no *prox;
}No;

typedef struct queue{
    No *head;
    No *end;
}Queue;

Queue *createQueue(){
    Queue *queue = malloc(sizeof(queue));
    if(queue == NULL)
        printf("Erro: malloc error.\n");
    
    queue->head = NULL;    
    queue->end = NULL;
    
    return queue;
    
}

int emptyQueue(Queue *queue){
    return (queue->head == NULL);
}

void enQueue(Queue *queue, int num){
    No *novoNo = malloc(sizeof(No));
    novoNo-> num = num;
    novoNo-> prox = NULL;
    
    if(emptyQueue(queue)){
        queue->head = novoNo;
        queue->end = novoNo;
    }
    else{
        queue->end->prox = novoNo;
        queue->end = novoNo;
    }
}
int through_queue(No*head){
    if(head->num == 45){
        printf("Found");
    }
    else if(head->prox != NULL){
        printf("%d\n",head->num);
        through_queue(head->prox);
    }
    else{
        return 1;
    }
}

int main()
{
    Queue *queue1 = createQueue();
    enQueue(queue1, 6);
    enQueue(queue1, 4);
    enQueue(queue1, 3);
    enQueue(queue1, 45);
    
    through_queue(queue1->head);


    return 0;
}
