#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Queue implementation using two stacks
typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
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
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to initialize the queue
void initQueue(Queue* queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Enqueue operation (insert an element into the queue)
void enqueue(Queue* queue, int value) {
    push(&queue->stack1, value);
}

// Dequeue operation (remove an element from the queue)
int dequeue(Queue* queue) {
    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            int temp = pop(&queue->stack1);
            push(&queue->stack2, temp);
        }
    }

    // If stack2 is still empty, the queue is empty
    if (isEmpty(&queue->stack2)) {
        printf("Queue Underflow\n");
        return -1;
    }

    return pop(&queue->stack2);
}

// Function to print the elements of the queue
void printQueue(Queue* queue) {
    // First, print elements of stack2 (front of the queue)
    for (int i = queue->stack2.top; i >= 0; i--) {
        printf("%d ", queue->stack2.items[i]);
    }

    // Then print elements of stack1 in reverse order (back of the queue)
    for (int i = 0; i <= queue->stack1.top; i++) {
        printf("%d ", queue->stack1.items[i]);
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue queue;
    initQueue(&queue);

    // Enqueue elements into the queue
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Queue after enqueuing elements: ");
    printQueue(&queue);

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    printf("Queue after dequeuing elements: ");
    printQueue(&queue);

    return 0;
}
