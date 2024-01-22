#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define N 1000
int nums[N], low[N];
bool visited[N];
vector<int> graph[N];
vector<int> order;
void topoSort(int cur)
{
    if (visited[cur]) return;
    visited[cur] = true;
    for (int node : graph[cur])
    {
        topoSort(node);
    }
    order.push_back(cur);
}
int main()
{
    int edges, n = 0;
    scanf("%d", &edges);
    while (edges--)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src].push_back(dest);
        n = max(n, max(src, dest));
    }
    int count = 1;
    for (int i = 1; i <= n; ++i) {
        topoSort(i);
    }
    //topoSort(1);
    reverse(order.begin(), order.end());
    for (int num : order) printf("%d ", num);
    return 0;
}