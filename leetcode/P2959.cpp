#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 1000000000;
struct Edge
{
    int to, w;
    Edge(int _to, int _w)
    {
        to = _to;
        w = _w;
    }
    bool operator<(const Edge &other)
    {
        return w < other.w;
    }
};
int dfs(vector<vector<int>> &graph, bool *visited, int branch, int distance) {
    int count = 0;
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && distance >= graph[branch][i]) {
            visited[i] = true;
            count += 1 + dfs(graph, visited, i, distance - graph[branch][i]);
            visited[i] = false;
        }
    }
    return count;
}
// int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
// {
//     int res = 0;
//     vector<vector<int>> graph(n, vector<int> (n, INF));
//     for (vector<int> &edge : roads) {
//         graph[edge[0]][edge[1]] = edge[2];
//         graph[edge[1]][edge[0]] = edge[2];
//     }
//     bool visited[1000];
//     for (int i = 0; i < n; ++i) {
//         fill(visited, visited + n, false);
//         res += dfs(graph, visited, i, maxDistance);
//     }
//     return res / 2 + n + 1;
// }
int getMaxDistance(int mask, int n, vector<vector<int>> d /* copy */) {
    int res = 0;
    for (int k = 0; k < n; ++k) // Floyd-Warshall
        if (mask & (1 << k))
            for (int i = 0; i < n; ++i)
                if (i != k && mask & (1 << i))
                    for (int j = 0; j < n; ++j)
                        if (j != i && mask & (1 << j))
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
    for (int i = 0; i < n; ++i)
        if (mask & (1 << i))
            for (int j = i + 1; j < n; ++j)
                if (mask & (1 << j))
                    res = max(res, d[i][j]);
    return res;
}
int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    vector<vector<int>> d(n, vector<int>(n, 100000));
    for (auto &r : roads) {
        d[r[0]][r[1]] = min(d[r[0]][r[1]], r[2]);
        d[r[1]][r[0]] = min(d[r[1]][r[0]], r[2]);
    }
    int comb = 1 << n, res = 1;
    for (int mask = 1; mask < comb; ++mask)
        res += getMaxDistance(mask, n, d) <= maxDistance;
    return res;
}
int getMaxDistance(int mask, vector<vector<int>> graph) {
    int n = graph.size(), res = 0;
    for (int k = 0; k < n; ++k) {
        if (!(mask & 1 << k)) continue;
        for (int i = 0; i < n; ++i) {
            if (k == i || !(mask & 1 << i)) continue;
            for (int j = 0; j < n; ++j) {
                if (i == j || !(mask & 1 << j)) continue;
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!(mask & 1 << i)) continue;
        for (int j = 0; j < n; ++j) {
            if (j == i || !(mask & 1 << j)) continue;
            res = max(res, graph[i][j]);
        }
    }
    return res;
}
int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
    {
        int res = 1;
        vector<vector<int>> graph(n, vector<int> (n, INF));
        for (vector<int> &edge : roads) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        int comb = 1 << n;
        for (int mask = 1; mask < comb; ++mask) {
            res += (getMaxDistance(mask, graph) <= maxDistance);
        }
        return res;
    }
}