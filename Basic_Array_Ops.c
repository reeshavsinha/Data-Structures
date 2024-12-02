#include <stdio.h>
#define MAX_SIZE 100  // Maximum size of the array

void insertElement(int arr[], int *size, int pos, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array overflow. Cannot insert element.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position. Enter position between 0 and %d.\n", *size);
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Array underflow. Cannot delete element.\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Invalid position. Enter position between 0 and %d.\n", *size - 1);
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

void traverseArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int accessElement(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position. Enter position between 0 and %d.\n", size - 1);
        return -1;  // Indicating an error
    }
    return arr[pos];
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;  // Current size of the array
    int choice, pos, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Traverse Array\n");
        printf("4. Access Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position to insert (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertElement(arr, &size, pos, value);
                break;

            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;

            case 3:
                traverseArray(arr, size);
                break;

            case 4:
                printf("Enter position to access (0 to %d): ", size - 1);
                scanf("%d", &pos);
                value = accessElement(arr, size, pos);
                if (value != -1) {
                    printf("Element at position %d is %d\n", pos, value);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
