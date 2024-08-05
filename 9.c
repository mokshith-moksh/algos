#include <stdio.h>
#include <time.h>
#define MAX 10

void selsort(int a[], int n) {
    int i, j, small, pos, temp;
    for (j = 0; j < n - 1; j++) {
        small = a[j];
        pos = j;
        for (i = j + 1; i < n; i++) {
            if (a[i] < small) {
                small = a[i];
                pos = i;
            }
        }
        // Swap the found minimum element with the first element
        temp = a[j];
        a[j] = a[pos];
        a[pos] = temp;
    }
}

int main() {
    int a[MAX], i, n;
    struct timespec start, end;
    double dura;

    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("The number of elements exceeds the maximum allowed.\n");
        return 1;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start);
    // Sort the array
    selsort(a, n);
    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the time taken in seconds
    dura = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Time taken is: %lf seconds\n", dura);
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
