#include <stdbool.h>
#include <stdlib.h>

bool dfs(int curr, int** adj, int* adjColSize, int* visited) {
    if (visited[curr] == 1) {
        return false;
    }
    if (visited[curr] == 2) {
        return true;
    }
    visited[curr] = 1;
    for (int i = 0; i < adjColSize[curr]; i++) {
        int nextCourse = adj[curr][i];
        if (!dfs(nextCourse, adj, adjColSize, visited)) {
            return false;
        }
    }
    visited[curr] = 2;
    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    if (numCourses <= 0) return true;
    int* adjColSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        int preReq = prerequisites[i][1];
        adjColSize[preReq]++;
    }
    int** adj = (int**)malloc(sizeof(int*) * numCourses);
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int*)malloc(sizeof(int) * adjColSize[i]);
    }
    int* curAdjColSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int preReq = prerequisites[i][1];
        adj[preReq][curAdjColSize[preReq]++] = course;
    }
    int* visited = (int*)calloc(numCourses, sizeof(int));
    bool possible = true;
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, adj, adjColSize, visited)) {
                possible = false;
                break;
            }
        }
    }
    free(visited);
    free(adjColSize);
    free(curAdjColSize);
    for (int i = 0; i < numCourses; i++) {
        free(adj[i]);
    }
    free(adj);
    return possible;
}