#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct DoublyCircularQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize the queue
void initializeQueue(struct DoublyCircularQueue* dcq) {
    dcq->front = dcq->rear = -1;
}

// Check if the queue is full
int isFull(struct DoublyCircularQueue* dcq) {
    return (dcq->rear + 1) % MAX_SIZE == dcq->front;
}

// Check if the queue is empty
int isEmpty(struct DoublyCircularQueue* dcq) {
    return dcq->front == -1;
}

// Enqueue operation
void enqueue(struct DoublyCircularQueue* dcq, int value) {
    if (isFull(dcq)) {
        printf("Queue is full!\n");
        return;
    }
    if (dcq->front == -1) {  // If the queue is empty
        dcq->front = dcq->rear = 0;
    } else {
        dcq->rear = (dcq->rear + 1) % MAX_SIZE;
    }
    dcq->arr[dcq->rear] = value;
}

// Dequeue operation
int dequeue(struct DoublyCircularQueue* dcq) {
    if (isEmpty(dcq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = dcq->arr[dcq->front];
    if (dcq->front == dcq->rear) {  // Only one element
        dcq->front = dcq->rear = -1;
    } else {
        dcq->front = (dcq->front + 1) % MAX_SIZE;
    }
    return value;
}

// Peek operation
int peek(struct DoublyCircularQueue* dcq) {
    if (isEmpty(dcq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return dcq->arr[dcq->front];
}

// Get the size of the queue
int size(struct DoublyCircularQueue* dcq) {
    if (isEmpty(dcq)) {
        return 0;
    }
    if (dcq->rear >= dcq->front) {
        return dcq->rear - dcq->front + 1;
    }
    return (MAX_SIZE - dcq->front) + dcq->rear + 1;
}

// Clear the queue
void clear(struct DoublyCircularQueue* dcq) {
    dcq->front = dcq->rear = -1;
    printf("Queue cleared.\n");
}

// Display the queue
void display(struct DoublyCircularQueue* dcq) {
    if (isEmpty(dcq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = dcq->front;
    while (i != dcq->rear) {
        printf("%d ", dcq->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", dcq->arr[dcq->rear]);
}

int main() {
    struct DoublyCircularQueue dcq;
    initializeQueue(&dcq);
    
    enqueue(&dcq, 1);
    enqueue(&dcq, 2);
    enqueue(&dcq, 3);
    display(&dcq);
    
    printf("Peek: %d\n", peek(&dcq));
    printf("Queue size: %d\n", size(&dcq));
    
    dequeue(&dcq);
    display(&dcq);
    
    clear(&dcq);
    display(&dcq);
    
    return 0;
}
