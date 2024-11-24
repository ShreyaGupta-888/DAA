//•	Rearrange an array in maximum minimum form using Two Pointer Technique. Input: arr[] = {1, 2, 3, 4, 5, 6, 7} Output: arr[] = {7, 1, 6, 2, 5, 3, 4}.

#include <stdio.h>
#include <stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void rearrangeMaxMin(int arr[], int n) {
    
    qsort(arr, n, sizeof(int), compare);

    
    int temp[n];


    int low = 0, high = n - 1;

    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            temp[i] = arr[high--]; 
        } else {
            temp[i] = arr[low++]; 
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
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

    rearrangeMaxMin(arr, n);

    printf("Array in maximum-minimum form:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
