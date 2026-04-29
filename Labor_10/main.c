#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int main() {
    int n, m;

    if (scanf("%d %d", &n, &m) != 2) return 1;

    Interval *intervals = (Interval *)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    Interval *result = (Interval *)malloc(n * sizeof(Interval));
    int res_count = 0;
    int current_end = 0;

    while (current_end < m) {
        int max_end = current_end;
        int best_idx = -1;

        for (int i = 0; i < n; i++) {
            if (intervals[i].start <= current_end && intervals[i].end > max_end) {
                max_end = intervals[i].end;
                best_idx = i;
            }
        }

        if (best_idx == -1) {
            printf("Nem lehet teljesen lefedni a szakaszt.\n");
            free(intervals);
            free(result);
            return 0;
        }

        result[res_count++] = intervals[best_idx];
        current_end = max_end;
    }

    printf("%d\n", res_count);
    for (int j = 0; j < res_count; j++) {
        printf("(%d,%d)", result[j].start, result[j].end);
        if (j < res_count - 1) printf(" ");
    }
    printf("\n");

    free(intervals);
    free(result);

    return 0;
}