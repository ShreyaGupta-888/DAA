//	Write a program to reverse an array.

#include <stdio.h>

int main() {
    int n, i;

   
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    int arr[n];

    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    
    int start = 0;
    int end = n - 1;
    while (start < end) {
       
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

       
        start++;
        end--;
    }

   
    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
