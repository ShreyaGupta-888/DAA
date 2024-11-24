//	Find sum of all array elements using recursion.


#include <stdio.h>
int recursive_sum(int arr[], int n) {
    
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + recursive_sum(arr, n - 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5}; 
    int n = sizeof(array) / sizeof(array[0]); 

    int total_sum = recursive_sum(array, n); 
    printf("Sum of array elements: %d\n", total_sum); 

    return 0;
}
