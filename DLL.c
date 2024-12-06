#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a specific position
void insertAtPosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

// Delete from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

// Delete from a specific position
void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1) {
        struct Node* temp = *head;
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
