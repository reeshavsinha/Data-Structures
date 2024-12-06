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

// Insert an element in a sorted stack
void insertSorted(Stack* stack, int value) {
    // Base case: if stack is empty or the top element is smaller than the value
    if (isEmpty(stack) || peek(stack) <= value) {
        push(stack, value);
        return;
    }

    // Recursively pop the top element
    int temp = pop(stack);

    // Insert the value in the correct position
    insertSorted(stack, value);

    // Push the popped element back
    push(stack, temp);
}

// Sort the stack using recursion
void sortStack(Stack* stack) {
    // Base case: If the stack is empty, return
    if (isEmpty(stack)) {
        return;
    }

    // Pop the top element
    int temp = pop(stack);

    // Sort the remaining stack
    sortStack(stack);

    // Insert the popped element back in the sorted order
    insertSorted(stack, temp);
}

// Function to print the stack
void printStack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Main function to test the sort function
int main() {
    Stack stack;
    initStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 5);
    push(&stack, 40);
    push(&stack, 30);

    printf("Original Stack: ");
    printStack(&stack);

    // Sort the stack
    sortStack(&stack);

    printf("Sorted Stack: ");
    printStack(&stack);

    return 0;
}
