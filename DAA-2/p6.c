// Store ‘n’ numbers (integers or real) in an array. Conduct a linear search for a given number and report success or failure in the form of a suitable message.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.000001 // Tolerance for comparing floating-point numbers

int compareFloat(float a, float b) {
    return fabs(a - b) < EPSILON;  // Returns 1 if a is approximately equal to b
}

int main() {
    int n, i;
    float *arr; 
    float searchNum;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d numbers (real numbers):\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%f", &arr[i]);
    }

    // Input number to search
    printf("Enter the number to search: ");
    scanf("%f", &searchNum);

    // Search for the number in the array
    int found = 0;
    for (i = 0; i < n; i++) {
        if (compareFloat(arr[i], searchNum)) {
            found = 1; 
            break;
        }
    }

    // Output result
    if (found) {
        printf("Number %.2f found in the array.\n", searchNum);
    } else {
        printf("Number %.2f not found in the array.\n", searchNum);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
