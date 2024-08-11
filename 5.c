#include <stdio.h>

void sort(int a[][10], int id[], int n, int temp[], int *k) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (id[i] == 0) {
            id[i] = -1; 
            temp[(*k)++] = i;
            for (j = 0; j < n; j++) {
                if (a[i][j] == 1 && id[j] != -1)
                    id[j]--;
            }
            i = -1; 
        }
    }
}

int main() {
    int a[10][10], id[10], temp[10], n, i, j, k = 0;
    printf("Enter the number of vertices (n value): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) id[i] = 0;

    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                id[j]++; 
        }
    }

    sort(a, id, n, temp, &k);

    if (k != n) {
        printf("Topological ordering not possible (cycle detected).\n");
    } else {
        printf("Topological ordering is: ");
        for (i = 0; i < k; i++) {
            printf("%d ", temp[i]);
        }
        printf("\n");
    }

    return 0;
}
