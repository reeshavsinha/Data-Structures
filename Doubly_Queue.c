#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct DoubleQueue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize deque
void initializeQueue(struct DoubleQueue* dq) {
    dq->front = -1;
    dq->rear = -1;
}

// Check if deque is full
int isFull(struct DoubleQueue* dq) {
    return dq->rear == MAX_SIZE - 1;
}

// Check if deque is empty
int isEmpty(struct DoubleQueue* dq) {
    return dq->front == -1;
}

// Enqueue operation at the rear
void enqueueRear(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("Queue is full!\n");
        return;
    }
    if (dq->front == -1) {  // If deque is empty
        dq->front = 0;
    }
    dq->arr[++dq->rear] = value;
}

// Enqueue operation at the front
void enqueueFront(struct DoubleQueue* dq, int value) {
    if (isFull(dq)) {
        printf("Queue is full!\n");
        return;
    }
    if (dq->front == -1) {  // If deque is empty
        dq->front = 0;
        dq->rear = 0;
    } else {
        for (int i = dq->rear; i >= dq->front; i--) {
            dq->arr[i + 1] = dq->arr[i];
        }
        dq->arr[dq->front] = value;
        dq->rear++;
    }
}

// Dequeue operation from the front
int dequeueFront(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear) {  // Only one element
        dq->front = dq->rear = -1;
    } else {
        dq->front++;
    }
    return value;
}

// Dequeue operation from the rear
int dequeueRear(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear) {  // Only one element
        dq->front = dq->rear = -1;
    } else {
        dq->rear--;
    }
    return value;
}

// Peek operation (view the front element)
int peekFront(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get the size of the deque
int size(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        return 0;
    }
    return dq->rear - dq->front + 1;
}

// Clear the deque
void clear(struct DoubleQueue* dq) {
    dq->front = dq->rear = -1;
    printf("Deque cleared.\n");
}

// Display the deque
void display(struct DoubleQueue* dq) {
    if (isEmpty(dq)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = dq->front; i <= dq->rear; i++) {
        printf("%d ", dq->arr[i]);
    }
    printf("\n");
}

int main() {
    struct DoubleQueue dq;
    initializeQueue(&dq);
    
    enqueueRear(&dq, 1);
    enqueueRear(&dq, 2);
    enqueueFront(&dq, 0);
    display(&dq);
    
    printf("Peek Front: %d\n", peekFront(&dq));
    printf("Queue size: %d\n", size(&dq));
    
    dequeueFront(&dq);
    dequeueRear(&dq);
    display(&dq);
    
    clear(&dq);
    display(&dq);
    
    return 0;
}
