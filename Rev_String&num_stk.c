#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum stack size for the string

// Stack implementation for characters
typedef struct {
    int top;
    char items[MAX];
} CharStack;

// Initialize the stack
void initCharStack(CharStack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmptyChar(CharStack *stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void pushChar(CharStack *stack, char value) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop a character from the stack
char popChar(CharStack *stack) {
    if (isEmptyChar(stack)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to reverse a string using a stack
void reverseString(char *str) {
    CharStack stack;
    initCharStack(&stack);

    // Push all characters onto the stack
    for (int i = 0; str[i] != '\0'; i++) {
        pushChar(&stack, str[i]);
    }

    // Pop characters to get the reversed string
    int i = 0;
    while (!isEmptyChar(&stack)) {
        str[i++] = popChar(&stack);
    }
}

// Stack implementation for digits of a number
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Push a digit onto the stack
Node *pushDigit(Node *top, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return top;
    }
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

// Pop a digit from the stack
int popDigit(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node *temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to reverse a number using a stack
int reverseNumber(int num) {
    Node *stack = NULL;

    // Push digits onto the stack
    while (num != 0) {
        stack = pushDigit(stack, num % 10);
        num /= 10;
    }

    // Pop digits to form the reversed number
    int reversedNum = 0;
    int placeValue = 1;
    while (stack != NULL) {
        reversedNum += popDigit(&stack) * placeValue;
        placeValue *= 10;
    }

    return reversedNum;
}

// Main function to demonstrate reversing a string and a number
int main() {
    char str[] = "Hello, World!";
    int num = 12345;

    // Reverse the string
    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);

    // Reverse the number
    printf("Original Number: %d\n", num);
    int reversedNum = reverseNumber(num);
    printf("Reversed Number: %d\n", reversedNum);

    return 0;
}
