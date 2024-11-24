//•	Move all zeroes to end of array

#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int count = 0; // Count of non-zero elements

    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count++] = arr[i]; 
        }
    }

   
    while (count < n) {
        arr[count++] = 0;
    }
}

int main() {
    int n;

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    int arr[n];

    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    
    moveZeroesToEnd(arr, n);

    
    printf("Array after moving zeroes to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}