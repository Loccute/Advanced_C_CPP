#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    int* items;
    int front;
    int rear;
    int size;
}Queue;

void initialize(Queue* queue, int size){
    queue->items = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

bool isfull(Queue queue)
{
    return queue.front == (queue.rear + 1) % queue.size;
}

void enqueue(Queue* queue, int value){
    if (isfull(*queue)) {
        printf("Queue overflow!\n");
        return;
    }
    if (queue->front == -1){
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->items[queue->rear] = value;
}

int dequeue(Queue* queue){
    if (queue->front == -1){
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else queue->front = (queue->front + 1) % queue->size;
    return value;
}

int front(Queue queue) {
    if (queue.front != -1) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}


void display(Queue queue){
    printf("The value of the queue: \n");
    int i = queue.front;
    while(i != queue.rear){
        printf("Value queue[%d] = %d, at address: %p\n", i, queue.items[i], &queue.items[i]);
        i = (i + 1) % queue.size;
        if (i == queue.rear) printf("Value queue[%d] = %d, at address: %p\n", i, queue.items[i], &queue.items[i]);
    }
}

int main(){
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(queue);
    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    
    display(queue);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));
    free(queue.items);

    return 0;
}
