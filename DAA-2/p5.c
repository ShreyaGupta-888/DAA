//	Find the product of two matrices using pointers.

#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int **a, int **b, int **result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j]; // Multiply and accumulate
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;


    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

  
    if (c1 != r2) {
        printf("Matrix multiplication is not possible!\n");
        return 1;
    }

    int **a = (int **)malloc(r1 * sizeof(int *));
    int **b = (int **)malloc(r2 * sizeof(int *));
    int **result = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++) {
        a[i] = (int *)malloc(c1 * sizeof(int));
        result[i] = (int *)malloc(c2 * sizeof(int));
    }
    for (int i = 0; i < r2; i++) {
        b[i] = (int *)malloc(c2 * sizeof(int));
    }

    
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }


    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    
    multiplyMatrices(a, b, result, r1, c1, c2);

    
    printf("\nProduct of the matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    
    for (int i = 0; i < r1; i++) {
        free(a[i]);
        free(result[i]);
    }
    for (int i = 0; i < r2; i++) {
        free(b[i]);
    }
    free(a);
    free(b);
    free(result);

    return 0;
}