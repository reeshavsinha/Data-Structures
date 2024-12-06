#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation using an array
typedef struct {
    int front, rear;
    int items[MAX];
} Queue;

// Stack implementation
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Function to initialize the queue
void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isQueueFull(Queue* queue) {
    return queue->rear == MAX - 1;
}

// Enqueue an element to the queue
void enqueue(Queue* queue, int value) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;  // If the queue is empty
    }
    queue->items[++queue->rear] = value;
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear) {  // Last element in the queue
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to reverse the first K elements of the queue
void reverseKElements(Queue* queue, int K) {
    if (isQueueEmpty(queue) || K <= 0) {
        printf("Invalid operation.\n");
        return;
    }

    Stack stack;
    initStack(&stack);

    // Step 1: Dequeue the first K elements and push them to the stack
    int count = 0;
    while (count < K && !isQueueEmpty(queue)) {
        int value = dequeue(queue);
        push(&stack, value);
        count++;
    }

    // Step 2: Pop elements from the stack and enqueue them back to the queue (this reverses their order)
    while (!isStackEmpty(&stack)) {
        int value = pop(&stack);
        enqueue(queue, value);
    }

    // Step 3: Move the remaining elements from the front of the queue to the back
    // These elements will remain in the same order
    int remaining = queue->rear - queue->front + 1 - K;
    for (int i = 0; i < remaining; i++) {
        int value = dequeue(queue);
        enqueue(queue, value);
    }
}

// Function to print the queue
void printQueue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Main function to test the reverse function
int main() {
    Queue queue;
    initQueue(&queue);

    // Enqueue some elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    
    printf("Original Queue: ");
    printQueue(&queue);

    // Reverse the first 3 elements of the queue
    int K = 3;
    reverseKElements(&queue, K);

    printf("Queue after reversing first %d elements: ", K);
    printQueue(&queue);

    return 0;
}
