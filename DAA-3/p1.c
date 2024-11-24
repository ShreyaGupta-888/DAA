// 	Implement the activity selection problem to get a clear understanding of greedy approach.

#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

void activity_selection(struct Activity activities[], int n) {

    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected Activities:\n");
    printf("Activity %d: (%d, %d)\n", 1, activities[0].start, activities[0].finish);

    int last_finish_time = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_finish_time) {
            printf("Activity %d: (%d, %d)\n", i + 1, activities[i].start, activities[i].finish);
            last_finish_time = activities[i].finish; // Update last finish time
        }
    }
}

int main() {
    struct Activity activities[] = {
        {0, 6},
        {1, 4},
        {3, 5},
        {5, 7},
        {8, 9},
        {5, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);
    activity_selection(activities, n);

    return 0;
}