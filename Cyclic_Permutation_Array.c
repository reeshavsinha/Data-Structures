#include <stdio.h>

void cyclicPermutation(int arr[], int size, char direction) {
    if (size <= 1) {
        printf("Array too small for cyclic permutation.\n");
        return;
    }

    if (direction == 'L' || direction == 'l') {
        // Left Cyclic Permutation
        int first = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first;
    } else if (direction == 'R' || direction == 'r') {
        // Right Cyclic Permutation
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    } else {
        printf("Invalid direction. Use 'L' for left or 'R' for right.\n");
        return;
    }

    printf("Array after cyclic permutation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    char direction;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the direction ('L' for left, 'R' for right): ");
    scanf(" %c", &direction); // Space before %c to consume newline character

    cyclicPermutation(arr, size, direction);

    return 0;
}
