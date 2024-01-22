#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define N 1000
int nums[N], low[N];
vector<int> graph[N];
void dfsAnalysis(int &order, int prev, int cur)
{
    nums[cur] = order;
    low[cur] = order;
    for (int node : graph[cur])
    {
        if (node == prev)
            continue;
        if (nums[node] == 0)
        {
            ++order;
            dfsAnalysis(order, cur, node);
        }
        low[cur] = min(low[cur], low[node]);
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
    dfsAnalysis(count, -1, 1);
    for (int i = 0; i < 15; ++i) {
        printf("%d. nums[%d] = %d, low[%d] = %d \n", i, i, nums[i], i, low[i]);
        //for (int node : graph[i]) if (low[i] > nums[node]) printf("Bridge: %d - %d\n", i, node);
    }
    return 0;
}