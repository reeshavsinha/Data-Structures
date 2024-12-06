#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Insert at a specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (*head == NULL && pos != 1) {
        printf("List is empty and position is invalid.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
        temp = temp->next;
    if (temp->next == *head && pos != 2) {
        printf("Position out of bounds.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) { // Only one node
        free(temp);
        *head = NULL;
        return;
    }
    struct Node* last = *head;
    while (last->next != *head)
        last = last->next;
    last->next = temp->next;
    *head = temp->next;
    free(temp);
}

// Delete from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) { // Only one node
        free(temp);
        *head = NULL;
        return;
    }
    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}

// Delete from a specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos && temp->next != *head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == *head && pos > 1) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtPosition(&head, 15, 2);
    displayList(head);
    deleteAtBeginning(&head);
    displayList(head);
    deleteAtEnd(&head);
    displayList(head);
    deleteAtPosition(&head, 1);
    displayList(head);
    return 0;
}
