//	Find the sum of rows and columns of matrix of given order (row x column).

#include <stdio.h>

int main() {
    int rows, cols;

   
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols]; 
    int rowSum[rows];       
    int colSum[cols];       

    
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
    }
    for (int j = 0; j < cols; j++) {
        colSum[j] = 0;
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j]; 
            colSum[j] += matrix[i][j]; 
        }
    }

   
    printf("\nSum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    printf("\nSum of each column:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}