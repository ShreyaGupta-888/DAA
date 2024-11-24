//Compare the Backtracking and Branch & Bound Approach by the implementation of 0/1 Knapsack problem. Also compare the performance with dynamic programming approach. (i)

#include <stdio.h>

int maxValue = 0;

void knapsackBacktracking(int W, int weights[], int values[], int n, int index, int currentWeight, int currentValue) {
    if (index == n) {
        if (currentValue > maxValue) {
            maxValue = currentValue;
        }
        return;
    }

    
    if (currentWeight + weights[index] <= W) {
        knapsackBacktracking(W, weights, values, n, index + 1, currentWeight + weights[index], currentValue + values[index]);
    }


    knapsackBacktracking(W, weights, values, n, index + 1, currentWeight, currentValue);
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int values[n], weights[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    knapsackBacktracking(W, weights, values, n, 0, 0, 0);
    printf("Maximum value using Backtracking: %d\n", maxValue);

    return 0;
}
