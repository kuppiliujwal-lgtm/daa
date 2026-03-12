#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX], queue[MAX];
int n, front = -1, rear = -1;

void bfs(int start) {
    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
