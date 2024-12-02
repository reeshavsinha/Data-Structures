#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize circular queue
void initializeQueue(struct CircularQueue* cq) {
    cq->front = cq->rear = -1;
}

// Check if the queue is full
int isFull(struct CircularQueue* cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

// Check if the queue is empty
int isEmpty(struct CircularQueue* cq) {
    return cq->front == -1;
}

// Enqueue operation
void enqueue(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full!\n");
        return;
    }
    if (cq->front == -1) {  // If queue is empty
        cq->front = 0;
    }
    cq->rear = (cq->rear + 1) % MAX_SIZE;
    cq->arr[cq->rear] = value;
}

// Dequeue operation
int dequeue(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = cq->arr[cq->front];
    if (cq->front == cq->rear) {  // Only one element
        cq->front = cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % MAX_SIZE;
    }
    return value;
}

// Peek operation (view the front element)
int peek(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return cq->arr[cq->front];
}

// Get the size of the queue
int size(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        return 0;
    }
    if (cq->rear >= cq->front) {
        return cq->rear - cq->front + 1;
    }
    return (MAX_SIZE - cq->front) + cq->rear + 1;
}

// Clear the queue
void clear(struct CircularQueue* cq) {
    cq->front = cq->rear = -1;
    printf("Queue cleared.\n");
}

// Display the queue
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = cq->front;
    while (i != cq->rear) {
        printf("%d ", cq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", cq->arr[cq->rear]);
}

int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);
    
    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    display(&cq);
    
    printf("Peek: %d\n", peek(&cq));
    printf("Queue size: %d\n", size(&cq));
    
    dequeue(&cq);
    display(&cq);
    
    clear(&cq);
    display(&cq);
    
    return 0;
}
