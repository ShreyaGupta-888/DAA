//•	Write a program to count the total number of nonzero elements in a two-dimensional array.

#include <stdio.h>

#define ROWS 3 
#define COLS 4 


int countNonZero(int arr[ROWS][COLS]) {
    int count = 0;

    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }

    return count; 
}

int main() {
    int arr[ROWS][COLS]; 

    
    printf("Enter elements for a %dx%d array:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    
    int nonZeroCount = countNonZero(arr);

    
    printf("Total number of non-zero elements: %d\n", nonZeroCount);

    return 0;
}