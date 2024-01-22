#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define N 1000
int nums[N], low[N];
bool IS_CUTPOINT[N];
vector<int> graph[N];
void dfsAnalysis(int &timer, int prev, int cur)
{
    nums[cur] = timer;
    low[cur] = timer;
    int  children = 0;
    for (int node : graph[cur])
    {
        if (node == prev)
            continue;
        if (nums[node] == 0)
        {
            ++children;
            ++timer;
            dfsAnalysis(timer, cur, node);
        }
        low[cur] = min(low[cur], low[node]);
        if (low[node] >= nums[cur] && prev != -1) IS_CUTPOINT[cur] = true; 
    }
    if (prev == -1 && children > 1) IS_CUTPOINT[cur] = true;
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
        if (IS_CUTPOINT[i]) printf("%d ", i);
        //for (int node : graph[i]) if (low[i] > nums[node]) printf("Bridge: %d - %d\n", i, node);
    }
    return 0;
}