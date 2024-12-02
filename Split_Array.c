#include <stdio.h>
#include <stdlib.h>

void splitArray(int arr[], int size, int n) {
    if (n <= 0 || n > size) {
        printf("Invalid number of sub-arrays. Please enter a value between 1 and %d.\n", size);
        return;
    }

    int subArraySize = size / n;        // Minimum size of each sub-array
    int remainder = size % n;          // Extra elements to distribute

    int startIndex = 0;
    for (int i = 0; i < n; i++) {
        int currentSubArraySize = subArraySize + (i < remainder ? 1 : 0); // Distribute extra elements
        printf("Sub-array %d: ", i + 1);
        for (int j = 0; j < currentSubArraySize; j++) {
            printf("%d ", arr[startIndex + j]);
        }
        startIndex += currentSubArraySize;
        printf("\n");
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int n;
    printf("Enter the number of sub-arrays to split into: ");
    scanf("%d", &n);

    splitArray(arr, size, n);

    return 0;
}
