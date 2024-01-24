#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int to, w;
    Edge(int _to, int _w) {
        to = _to;
        w = _w;
    }
    bool operator<(const Edge& other) {
        return w < other.w;
    }
};
void weightedGraph() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        graph[from].push_back(Edge(to, w));
        graph[to].push_back(Edge(from, w));
    }
}
void unweightedGraph() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}
void denseGraph() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from][to] = true;
        graph[to][from] = true;
    }
}
void denseWeightedGraph() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        graph[from][to] = w;
        graph[to][from] = w;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        graph[from].push_back(Edge(to, w));
        graph[to].push_back(Edge(from, w));
    }
    return 0;
}