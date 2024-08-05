#include <stdio.h>

#define INF 999
#define MAX 100

int p[MAX], c[MAX][MAX], t[MAX][2];

int find(int v) {
    while (p[v])
        v = p[v];
    return v;
}

void union1(int i, int j) {
    p[j] = i;
}

void kruskal(int n) {
    int i, j, k, u, v, min, res1, res2, sum = 0;

    for (k = 1; k < n; k++) {
        min = INF;
        res1 = res2 = -1;
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i != j && c[i][j] < min) {
                    u = find(i);
                    v = find(j);
                    if (u != v) {
                        res1 = i;
                        res2 = j;
                        min = c[i][j];
                    }
                }
            }
        }

        if (res1 != -1 && res2 != -1) {
            union1(find(res1), find(res2));
            t[k][0] = res1;
            t[k][1] = res2;
            sum += min;
        }
    }

    printf("\nCost of spanning tree is=%d", sum);
    printf("\nEdges of spanning tree are:\n");
    for (i = 1; i < n; i++) {
        if (t[i][0] != 0 && t[i][1] != 0) {
            printf("%d -> %d\n", t[i][0], t[i][1]);
        }
    }
}

int main() {
    int i, j, n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++)
        p[i] = 0;

    printf("\nEnter the graph data (adjacency matrix):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] == 0 && i != j)
                c[i][j] = INF;
        }
    }

    kruskal(n);
    return 0;
}
