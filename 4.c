#include<stdio.h>
#define INF 999

void dijkstra(int c[10][10], int n, int s, int dist[10]) {
    int v[10], min, u, i, j;
    for (i = 0; i < n; i++) {
        v[i] = 0;
        dist[i] = c[s][i];
    }
    v[s] = 1;
    dist[s] = 0;

    for (i = 1; i < n; i++) { 
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!v[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break; 
        v[u] = 1;

        for (j = 0; j < n; j++) {
            if (!v[j] && c[u][j] != INF && (dist[u] + c[u][j] < dist[j])) {
                dist[j] = dist[u] + c[u][j];
            }
        }
    }
}

int main() {
    int c[10][10], dist[10], i, j, s, n;
    printf("Enter n value: ");
    scanf("%d", &n);
    printf("Enter the graph data:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &s);

    dijkstra(c, n, s, dist);

    for (i = 0; i < n; i++) {
        printf("Shortest distance from %d to %d is %d\n", s, i, dist[i]);
    }

    return 0;
}
