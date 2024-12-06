#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack implementation for characters
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1; // Return -1 if stack is empty
    }
    return stack->items[stack->top--];
}

// Function to check if parentheses are balanced
int checkBalancedParentheses(char *expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expr[i] != '\0'; i++) {
        char current = expr[i];

        // If it's an opening parenthesis, push it onto the stack
        if (current == '(') {
            push(&stack, current);
        }
        // If it's a closing parenthesis, pop from the stack
        else if (current == ')') {
            if (isEmpty(&stack)) {
                return 0; // If stack is empty, the parentheses are unbalanced
            }
            pop(&stack); // Pop the matching opening parenthesis
        }
    }

    // If stack is empty, the parentheses are balanced, otherwise unbalanced
    return isEmpty(&stack);
}

// Main function to test the checkBalancedParentheses function
int main() {
    char expr1[] = "((()))";
    char expr2[] = "(()";
    char expr3[] = "(()())";

    printf("Expression 1: %s is %s\n", expr1, checkBalancedParentheses(expr1) ? "Balanced" : "Unbalanced");
    printf("Expression 2: %s is %s\n", expr2, checkBalancedParentheses(expr2) ? "Balanced" : "Unbalanced");
    printf("Expression 3: %s is %s\n", expr3, checkBalancedParentheses(expr3) ? "Balanced" : "Unbalanced");

    return 0;
}
