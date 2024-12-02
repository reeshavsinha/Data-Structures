#include <stdio.h>
#include <stdlib.h>

void rotateArray(int arr[], int size, int k, char direction) {
    int *temp = (int *)malloc(size * sizeof(int));
    k = k % size; // Handle cases where k > size

    if (direction == 'L' || direction == 'l') {
        // Left Rotation
        for (int i = 0; i < size; i++) {
            temp[i] = arr[(i + k) % size];
        }
    } else if (direction == 'R' || direction == 'r') {
        // Right Rotation
        for (int i = 0; i < size; i++) {
            temp[(i + k) % size] = arr[i];
        }
    } else {
        printf("Invalid direction. Use 'L' for left or 'R' for right.\n");
        free(temp);
        return;
    }

    printf("Rotated Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    free(temp);
}

int main() {
    int size, k;
    char direction;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    printf("Enter the direction ('L' for left, 'R' for right): ");
    scanf(" %c", &direction); // Space before %c to consume newline character

    rotateArray(arr, size, k, direction);

    return 0;
}
