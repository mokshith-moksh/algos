#include <stdio.h>
#define MAX 10

int w[MAX], x[MAX], d;

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;
    if (p + w[k] == d) {
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
    } else if (p + w[k] + w[k + 1] <= d) {
        sumofsub(p + w[k], k + 1, r - w[k]);
    }
    if ((p + r - w[k] >= d) && (p + w[k + 1] <= d)) {
        x[k] = 0;
        sumofsub(p, k + 1, r - w[k]);
    }
}

int main() {
    int i, n, sum = 0;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the set elements in increasing order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    printf("Enter the maximum subset sum value: ");
    scanf("%d", &d);
    for (i = 0; i < n; i++) {
        sum += w[i];
    }
    if (sum < d || w[0] > d) {
        printf("No subset possible\n");
    } else {
        sumofsub(0, 0, sum);
    }
    return 0;
}
