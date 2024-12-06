#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

// Stack implementation for integers
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an integer onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an integer from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Return -1 if stack is empty
    }
    return stack->items[stack->top--];
}

// Function to perform arithmetic operations
int operate(int a, int b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// Evaluate Postfix expression
int evaluatePostfix(char *expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        // If the current character is a digit, push it onto the stack
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        }
        // If the current character is an operator, pop two operands and apply the operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = operate(a, b, expr[i]);
            push(&stack, result);
        }
    }

    // The final result is the only element left in the stack
    return pop(&stack);
}

// Evaluate Prefix expression
int evaluatePrefix(char *expr) {
    Stack stack;
    initStack(&stack);

    // Traverse the expression from right to left
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        // If the current character is a digit, push it onto the stack
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        }
        // If the current character is an operator, pop two operands and apply the operator
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int a = pop(&stack);
            int b = pop(&stack);
            int result = operate(a, b, expr[i]);
            push(&stack, result);
        }
    }

    // The final result is the only element left in the stack
    return pop(&stack);
}

// Main function to demonstrate the evaluation of Postfix and Prefix expressions
int main() {
    char postfixExpr[] = "23*54*+9-";   // Example Postfix expression
    char prefixExpr[] = "-+*23*54+9";   // Example Prefix expression

    printf("Postfix Evaluation Result: %d\n", evaluatePostfix(postfixExpr));
    printf("Prefix Evaluation Result: %d\n", evaluatePrefix(prefixExpr));

    return 0;
}
