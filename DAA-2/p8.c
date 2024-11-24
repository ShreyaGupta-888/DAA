//•	Find the largest three distinct elements in an array: Input: arr[] = {10, 4, 3, 50, 23, 90} Output: 90, 50, 23

#include <stdio.h>
#include <limits.h>

void findLargestThreeDistinct(int arr[], int n) {
    int first, second, third;

    
    first = second = third = INT_MIN;

    for (int i = 0; i < n; i++) {
        
        if (arr[i] > first) {
            third = second; 
            second = first; 
            first = arr[i]; 
        } else if (arr[i] > second && arr[i] != first) {
            third = second; 
            second = arr[i]; 
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i]; 
        }
    }

    if (third == INT_MIN) {
        printf("There are less than three distinct elements in the array.\n");
    } else {
        printf("The largest three distinct elements are: %d, %d, %d\n", first, second, third);
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

  
    findLargestThreeDistinct(arr, n);

    return 0;
}