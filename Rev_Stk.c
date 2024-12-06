#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
typedef struct {
    int top;
    int items[MAX];
} Stack;

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

// Insert an element at the bottom of the stack
void insertAtBottom(Stack* stack, int value) {
    // Base case: if stack is empty, insert the value
    if (isEmpty(stack)) {
        push(stack, value);
        return;
    }

    // Pop the top element
    int temp = pop(stack);

    // Recursively insert the value at the bottom
    insertAtBottom(stack, value);

    // Push the popped element back to the stack
    push(stack, temp);
}

// Reverse the stack using recursion
void reverseStack(Stack* stack) {
    // Base case: if stack is empty, return
    if (isEmpty(stack)) {
        return;
    }

    // Pop the top element
    int temp = pop(stack);

    // Recursively reverse the rest of the stack
    reverseStack(stack);

    // Insert the popped element at the bottom
    insertAtBottom(stack, temp);
}

// Function to print the stack
void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Main function to test the reverse function
int main() {
    Stack stack;
    initStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Original Stack: ");
    printStack(&stack);

    // Reverse the stack
    reverseStack(&stack);

    printf("Reversed Stack: ");
    printStack(&stack);

    return 0;
}
