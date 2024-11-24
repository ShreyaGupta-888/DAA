//	Get a detailed insight of dynamic programming approach by the implementation of Matrix Chain Multiplication problem and see the impact of parenthesis positioning on time requirements for matrix multiplication.

#include <stdio.h>
#include <limits.h>

#define MAX 100


void matrix_chain_order(int p[], int n, int m[MAX][MAX], int s[MAX][MAX]) {
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0; 
    }

    
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1; 
            m[i][j] = INT_MAX; 

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; 
                }
            }
        }
    }
}

void print_optimal_parens(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    
    int p[] = {30, 35, 15, 5, 10, 20, 25}; 
    int n = sizeof(p) / sizeof(p[0]) - 1; 

    int m[MAX][MAX]; 
    int s[MAX][MAX]; 
    matrix_chain_order(p, n, m, s);

    printf("Minimum number of multiplications is %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    print_optimal_parens(s, 1, n);
    printf("\n");

    return 0;
}