#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation (insert at the rear)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {  // If queue is empty
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

// Dequeue operation (remove from the front)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {  // Only one element
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Peek operation (view the front element)
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

// Get the size of the queue
int size(struct Queue* q) {
    if (isEmpty(q)) {
        return 0;
    }
    return q->rear - q->front + 1;
}

// Clear the queue
void clear(struct Queue* q) {
    q->front = q->rear = -1;
    printf("Queue cleared.\n");
}

// Search for an element in the queue
int search(struct Queue* q, int value) {
    if (isEmpty(q)) {
        return -1;
    }
    for (int i = q->front; i <= q->rear; i++) {
        if (q->arr[i] == value) {
            return i;
        }
    }
    return -1;  // Element not found
}

// Display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    
    printf("Peek: %d\n", peek(&q));
    printf("Queue size: %d\n", size(&q));
    
    dequeue(&q);
    display(&q);
    
    printf("Search for 2: %d\n", search(&q, 2));  // Returns index or -1 if not found
    
    clear(&q);
    display(&q);
    
    return 0;
}
