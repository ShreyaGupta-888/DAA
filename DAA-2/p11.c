//	Print all Distinct ( Unique ) Elements in given Array: Input: arr[] = {12, 10, 9, 45, 2, 10, 10, 45} Output: 12, 10, 9, 2

#include <stdio.h>

#define MAX_SIZE 100 

void printDistinct(int arr[], int n) {
    int distinct[MAX_SIZE] = {0}; 
    int isDistinct;

    printf("Distinct elements are: ");

    for (int i = 0; i < n; i++) {
        isDistinct = 1; 
        
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = 0; 
                break;
            }
        }

       
        if (isDistinct) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
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

    
    printDistinct(arr, n);

    return 0;
}