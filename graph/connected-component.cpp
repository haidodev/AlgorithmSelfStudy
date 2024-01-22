#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
#define N 1000
int nums[N], low[N];
vector<int> graph[N];
void TPLT(stack<int> &nodes, int &order, int prev, int cur)
{
    nodes.push(cur);
    nums[cur] = order;
    low[cur] = order;
    for (int node : graph[cur])
    {
        if (node == prev)
            continue;
        if (nums[node] == 0)
        {
            ++order;
            TPLT(nodes, order, cur, node);
        }
        low[cur] = min(low[cur], low[node]);
    }
    if (nums[cur] == low[cur]) {
        cout << "Connected Component: ";
        int node;
        do {
            node = nodes.top();
            nodes.pop();
            cout << node << " ";
        } while (node != cur);
        printf("\n");
    }
}
int main()
{
    int edges;
    scanf("%d", &edges);
    while (edges--)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    int count = 1;
    stack<int> nodes;
    TPLT(nodes, count, -1, 1);
    
    return 0;
}