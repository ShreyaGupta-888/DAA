// Through 0/1 Knapsack problem, analyze the greedy and dynamic programming approach for the same dataset. (i)greedy

#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

// Comparison function for sorting items by value-to-weight ratio in descending order
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r1 < r2) ? 1 : -1; 
}

double greedyKnapsack(struct Item items[], int n, int capacity) {
    // Sort items by value-to-weight ratio in descending order
    qsort(items, n, sizeof(items[0]), compare);

    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        // If the item can completely fit in the knapsack
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fractional part of the item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;  // Since the knapsack is full now
        }
    }
    return totalValue;
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = greedyKnapsack(items, n, capacity);
    printf("Maximum value in Greedy Knapsack = %.2f\n", maxValue);

    return 0;
}
