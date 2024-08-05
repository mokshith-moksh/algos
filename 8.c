#include <stdio.h>
#define MAX 10

int s[MAX], x[MAX], d;

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;
    if (p + s[k] == d) {
        for (i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", s[i]);
        }
        printf("\n");
    } else if (p + s[k] + s[k + 1] <= d) {
        sumofsub(p + s[k], k + 1, r - s[k]);
    }
    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d)) {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main() {
    int i, n, sum = 0;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the set elements in increasing order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    printf("Enter the maximum subset sum value: ");
    scanf("%d", &d);
    for (i = 0; i < n; i++) {
        sum += s[i];
    }
    if (sum < d || s[0] > d) {
        printf("No subset possible\n");
    } else {
        sumofsub(0, 0, sum);
    }
    return 0;
}
