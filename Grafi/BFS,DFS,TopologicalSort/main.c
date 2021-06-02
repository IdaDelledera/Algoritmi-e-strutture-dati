#include <stdio.h>

#include "queue.h"

void bfs(int graph[][4], int start, int n);

void dfs(int graph[][4], int start, int n);



void topologicalSort(int graph[][8], int start, int n);

int topologicalSortArray[8];
int counter = 8;


int main() {

    int graph[4][4] = {{0, 1, 0, 0},
                       {0, 0, 0, 1},
                       {0, 0, 0, 0,},
                       {0, 0, 1, 0}};

    printf("BFS:\n");
    bfs(graph, 1, 4);
    puts("\n");
    printf("DFS:\n");
    dfs(graph, 1, 4);
    puts("\n");

    printf("Topological Sort\n");
    topologicalSort(graph, 1, 4);

    for (int i = 1; i < 8; ++i) {
        printf("%i, ", topologicalSortArray[i]);
    }




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


void dfs(int graph[][4], int start, int n){

    int j;
    int visited[8]={0};

    if (visited[start]==0){
        printf("%d, ", start);
        visited[start]=1;

        for (j=1;j<n;j++){
            if (graph[start][j]==1 && visited[j]==0){
                dfs(graph, j, n);
            }
        }
    }
}

void topologicalSort(int graph[][8], int start, int n){
    int j;
    static int visited[8] = {0};

    if (visited[start] == 0){
        topologicalSortArray[--counter] = start;
        visited[start]=1;

        for (j = 1; j < n; j++) {
            if (graph[start][j] == 1 && visited[j]==0){
                topologicalSort(graph, j, n);
            }
        }
    }
}

