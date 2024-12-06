#include <stdio.h>
#include <stdlib.h>

// Queue implementation using a simple linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front, *rear;
} Queue;

// Initialize a queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue an element to the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Peek the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Stack using two queues
typedef struct Stack {
    Queue q1, q2;
} Stack;

// Initialize a stack
void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

// Push an element onto the stack
void push(Stack* s, int data) {
    // Push to the empty queue (q2)
    enqueue(&s->q2, data);

    // Move all elements from q1 to q2
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

// Peek the top element of the stack
int top(Stack* s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(&s->q1);
}

// Main function to demonstrate stack operations using two queues
int main() {
    Stack s;
    initStack(&s);

    // Push elements onto the stack
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top of the stack: %d\n", top(&s));  // Should be 30

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&s));  // Should be 30
    printf("Top of the stack after pop: %d\n", top(&s));  // Should be 20

    printf("Popped element: %d\n", pop(&s));  // Should be 20
    printf("Popped element: %d\n", pop(&s));  // Should be 10

    // Try popping from an empty stack
    printf("Popped element from empty stack: %d\n", pop(&s));  // Should indicate underflow

    return 0;
}
