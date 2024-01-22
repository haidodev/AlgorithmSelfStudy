#include <iostream>
#define N 1000
using namespace std;
int visited[N];
struct Edge {
    int src, dest, weight;
    Edge(int _src, int _dest, int _weight) {
        src = _src;
        dest = _dest;
        weight = _weight;
    }
};
struct UnionFind {
    int parent[N];
    int size[N];
    UnionFind(int n) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (size[px] < size[py]) swap(px, py);
        parent[py] = px;
        size[px] += size[py];
    }
};
vector<Edge> Kruskal(vector<Edge>& edges, int verticesCnt) {
    sort(edges.begin(), edges.end(), [](Edge const &a, Edge const &b) {
        return a.weight < b.weight;
    });
    vector<Edge> minSpanningTree;
    UnionFind uf(verticesCnt);
    for (Edge &edge: edges) {
        if (uf.find(edge.src) != uf.find(edge.dest)) {
            uf.unite(edge.src, edge.dest);
            minSpanningTree.push_back(edge);
        }
    }
    return minSpanningTree;
}
int main()
{
    int edgesCnt, verticesCnt;
    scanf("%d", &edgesCnt);
    vector<Edge> edges;
    while (edgesCnt--) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        Edge e(src, dest, weight);
        edges.push_back(e);
        verticesCnt = max(verticesCnt, max(src, dest));
    }
    vector<Edge> minSpanningTree = Kruskal(edges, verticesCnt);
    for (Edge &edge: minSpanningTree) {
        printf("%d %d %d\n", edge.src, edge.dest, edge.weight);
    }
    return 0;
}