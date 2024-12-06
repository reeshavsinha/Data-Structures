#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

// Peek the top element of the stack
char peek(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}

// Get the precedence of operators
int precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '^') return 3;
    return 0;
}

// Check if a character is an operand
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Infix to Postfix conversion
void infixToPostfix(char *expr, char *postfix) {
    Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char current = expr[i];

        if (isOperand(current)) {
            postfix[k++] = current;  // Add operands to the result
        } else if (current == '(') {
            push(&stack, current);  // Push '(' to the stack
        } else if (current == ')') {
            // Pop until '(' is encountered
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  // Pop the '('
        } else {
            // Handle operators
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);  // Push current operator to the stack
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

// Infix to Prefix conversion
void infixToPrefix(char *expr, char *prefix) {
    int len = strlen(expr);
    char reversed[MAX];
    int k = 0;

    // Step 1: Reverse the infix expression
    for (int i = len - 1; i >= 0; i--) {
        reversed[k++] = expr[i];
    }
    reversed[k] = '\0';

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    // Step 3: Convert the modified expression to postfix
    char reversedPostfix[MAX];
    infixToPostfix(reversed, reversedPostfix);

    // Step 4: Reverse the postfix expression to get the prefix expression
    int j = 0;
    for (int i = strlen(reversedPostfix) - 1; i >= 0; i--) {
        prefix[j++] = reversedPostfix[i];
    }
    prefix[j] = '\0';  // Null-terminate the prefix expression
}

// Main function to demonstrate the conversion
int main() {
    char infixExpr[] = "(A-B/C)*(A/K-L)";
    char postfixExpr[MAX];
    char prefixExpr[MAX];

    infixToPostfix(infixExpr, postfixExpr);
    printf("Infix to Postfix: %s\n", postfixExpr);

    infixToPrefix(infixExpr, prefixExpr);
    printf("Infix to Prefix: %s\n", prefixExpr);

    return 0;
}
