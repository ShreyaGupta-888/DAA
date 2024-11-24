//	Implement the sum of subset 


#include <stdio.h>

void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void sumOfSubset(int set[], int subset[], int n, int subsetSize, int total, int target, int index) {
    if (total == target) {
    
        printSubset(subset, subsetSize);
        return;
    }
    if (index >= n || total > target) {
        
        return;
    }


    subset[subsetSize] = set[index];
    sumOfSubset(set, subset, n, subsetSize + 1, total + set[index], target, index + 1);


    sumOfSubset(set, subset, n, subsetSize, total, target, index + 1);
}

int main() {
    int n, target;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n], subset[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with the sum %d:\n", target);
    sumOfSubset(set, subset, n, 0, 0, target, 0);

    return 0;
}

