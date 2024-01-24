#include <iostream>
#include <vector>
#include <algorithm>
#define N 21
using namespace std;

int graph[N][N];
bool visited[N];
int TSPBacktracking(int n, int graph[N][N], int current, int visitedCount) {
    if (visitedCount == n) return minDistance + graph[current][0];
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            minDistance = min(minDistance, TSPBacktracking(n, graph, i, visitedCount + 1));
            visited[i] = false;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j= 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    
}