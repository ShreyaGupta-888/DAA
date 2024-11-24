//Write a program using pointers to interchange the second biggest and the second smallest number in the array.

#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100 


void findSecondSmallestAndLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    int smallest = INT_MAX, largest = INT_MIN;
    *secondSmallest = INT_MAX; 
    *secondLargest = INT_MIN;  

    for (int i = 0; i < n; i++) {
       
        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *secondSmallest && arr[i] != smallest) {
            *secondSmallest = arr[i];
        }

       
        if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != largest) {
            *secondLargest = arr[i];
        }
    }
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    int arr[MAX_SIZE];

    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int secondSmallest, secondLargest;

    
    
    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

   
    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);

  
  
    for (int i = 0; i < n; i++) {
        if (arr[i] == secondSmallest) {
            arr[i] = secondLargest;
            
        } else if (arr[i] == secondLargest) {
            arr[i] = secondSmallest; 
            
        }
    }

    
    printf("Array after swapping second smallest and second largest:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
 