#include <stdio.h>
#include <stdbool.h>

// Function to check if an element exists in an array
bool isElementInArray(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }
    return false;
}

// Function to find the union of two sets
void unionOfSets(int arr1[], int size1, int arr2[], int size2) {
    int result[size1 + size2];
    int resultSize = 0;

    // Add all elements of the first array to the result
    for (int i = 0; i < size1; i++) {
        result[resultSize++] = arr1[i];
    }

    // Add elements of the second array only if they are not in the result
    for (int i = 0; i < size2; i++) {
        if (!isElementInArray(arr1, size1, arr2[i])) {
            result[resultSize++] = arr2[i];
        }
    }

    printf("Union: ");
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

// Function to find the intersection of two sets
void intersectionOfSets(int arr1[], int size1, int arr2[], int size2) {
    printf("Intersection: ");
    for (int i = 0; i < size1; i++) {
        if (isElementInArray(arr2, size2, arr1[i])) {
            printf("%d ", arr1[i]);
        }
    }
    printf("\n");
}

// Function to find the difference of two sets (A - B)
void differenceOfSets(int arr1[], int size1, int arr2[], int size2) {
    printf("Difference (A - B): ");
    for (int i = 0; i < size1; i++) {
        if (!isElementInArray(arr2, size2, arr1[i])) {
            printf("%d ", arr1[i]);
        }
    }
    printf("\n");
}

int main() {
    int size1, size2;

    // Input first array
    printf("Enter the size of the first set: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Enter the elements of the first set: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input second array
    printf("Enter the size of the second set: ");
    scanf("%d", &size2);
    int arr2[size2];
    printf("Enter the elements of the second set: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Perform set operations
    unionOfSets(arr1, size1, arr2, size2);
    intersectionOfSets(arr1, size1, arr2, size2);
    differenceOfSets(arr1, size1, arr2, size2);

    return 0;
}
