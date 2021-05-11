#include <stdio.h>

#include "queue.h"

void bfs(int graph[][4], int start, int n);

int main() {

    int graph[4][4] = {{0, 1, 0, 0},
                       {0, 0, 0, 1},
                       {0, 0, 0, 0,},
                       {0, 0, 1, 0}};

    printf("BFS:\n");
    bfs(graph, 1, 4);

}


void bfs(int graph[][4], int start, int n) {

    int i = start, j;
    int visited[4] = {0};

    printf("%d, ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        i = dequeue();

        for (j = i; j < n; j++) {
            if (graph[i][j] == 1 && visited[j] == 0) {
                printf("%d, ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

}