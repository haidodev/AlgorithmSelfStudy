#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
#define N 1000
bool visited[N];
struct Edge {
    int dest, weight;
    Edge() {
        dest = -1;
        weight = INF;
    }
    Edge(int _dest, int _weight) {
        dest = _dest;
        weight = _weight;
    }
};

void DensePrim(int graph[N][N], int verticesCnt) {
    int total_weight = 0;
    bool visited[N] = { false };
    vector<Edge> min_e(verticesCnt + 1);
    min_e[1].weight = 0;
    
    for (int i = 1; i <= verticesCnt; ++i) {
        int v = -1;
        for (int j = 1; j <= verticesCnt; ++j) {
            if (!visited[j] && (v == -1 || min_e[j].weight < min_e[v].weight)) v = j;
        }
        if (min_e[v].weight == INF) {
            cout << "No MST!" << endl;
            return ;
        }

        visited[v] = true;
        total_weight += min_e[v].weight;
        if (min_e[v].dest != -1) {
            cout << v << " " << min_e[v].dest << endl;
        }
        for (int dest = 1; dest <= verticesCnt; ++dest) {
            if (graph[v][dest] < min_e[dest].weight) {
                min_e[dest] = {v, graph[v][dest]};
            }
        }
    }
    cout << total_weight << endl;

}
int main()
{
    int graph[N][N];
    for (int i = 0; i < N; ++i) { 
        for (int j = 0; j < N; ++j) graph[i][j] = INF;
    }
    int edgesCnt, verticesCnt;
    scanf("%d %d", &edgesCnt, &verticesCnt);
    while (edgesCnt--) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
    DensePrim(graph, verticesCnt);
    return 0;
}