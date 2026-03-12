#include <stdio.h>
#include <limits.h>

#define MAX 20

int main() {
    int n, graph[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0;
    int min, x = 0, y = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }
    }

    visited[0] = 1;  // start from vertex 0

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1) {
        min = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                for(int j = 0; j < n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);
        totalCost += graph[x][y];
        visited[y] = 1;
        edges++;
    }

    printf("Total cost = %d\n", totalCost);

    return 0;
}
