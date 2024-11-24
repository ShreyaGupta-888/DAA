//Compare the Backtracking and Branch & Bound Approach by the implementation of 0/1 Knapsack problem. Also compare the performance with dynamic programming approach. (ii)

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
} Node;


float calculateBound(Node u, int n, int W, int weights[], int values[]) {
    if (u.weight >= W) {
        return 0; 
    }

    float bound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

   
    while (j < n && totalWeight + weights[j] <= W) {
        totalWeight += weights[j];
        bound += values[j];
        j++;
    }

    
    if (j < n) {
        bound += (W - totalWeight) * (float)values[j] / weights[j];
    }

    return bound;
}


int knapsackBranchAndBound(int n, int W, int weights[], int values[]) {
    
    Node queue[n];
    int maxProfit = 0;
    int front = 0, rear = 0;

   
    Node u = { -1, 0, 0, 0 };
    u.bound = calculateBound(u, n, W, weights, values);
    queue[rear++] = u;

    while (front < rear) {
        u = queue[front++];

        if (u.level == n - 1 || u.bound <= maxProfit) {
            continue;
        }

       
        Node v = { u.level + 1, u.profit + values[u.level + 1], u.weight + weights[u.level + 1], 0 };
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }
        v.bound = calculateBound(v, n, W, weights, values);
        if (v.bound > maxProfit) {
            queue[rear++] = v;
        }

       
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = calculateBound(v, n, W, weights, values);
        if (v.bound > maxProfit) {
            queue[rear++] = v;
        }
    }

    return maxProfit;
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

    int maxProfit = knapsackBranchAndBound(n, W, weights, values);
    printf("Maximum value using Branch & Bound: %d\n", maxProfit);

    return 0;
}
