#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int *arr, int oldSize, int newSize) {
    int *newArr = (int *)malloc(newSize * sizeof(int));
    for (int i = 0; i < (oldSize < newSize ? oldSize : newSize); i++) {
        newArr[i] = arr[i];
    }
    return newArr;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int oldSize = sizeof(arr) / sizeof(arr[0]);
    int newSize = 8;  // Change this value to resize to a different size
    
    printf("Original Array: ");
    for (int i = 0; i < oldSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *newArr = resizeArray(arr, oldSize, newSize);

    printf("Resized Array: ");
    for (int i = 0; i < newSize; i++) {
        if (i < oldSize)
            printf("%d ", newArr[i]);
        else
            printf("0 ");  // Uninitialized elements in new space
    }
    printf("\n");

    free(newArr);
    return 0;
}
