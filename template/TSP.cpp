#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define N 21
using namespace std;

int graph[N][N];
int dp[1 << N][N];

int TSPBitmaskDP(int n, int graph[N][N]){
    int comb = 1 << n;
    for (int i = 0; i < comb; ++i) fill(dp[i], dp[i] + N, 1e9);
    dp[1][0] = 0;
    for (int mask = 1; mask < comb; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && (mask & (1 << j))) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + graph[j][i]);
                    }
                }
            }
        }
    }
    int minDistance = 1e9;
    for (int i = 1; i < n; ++i) {
        minDistance = min(minDistance, dp[comb - 1][i] + graph[i][0]);
    }
    return minDistance;
}
int iMem[1 << N][N];
int TSP(int n, int i, int mask) {
    if (mask == (1 << n) - 1) return graph[i][0];
    if (iMem[mask][i] != -1) return iMem[mask][i];
    int minDistance = 1e9;
    for (int j = 0; j < n; ++j) {
        if (i != j && !(mask & (1 << j))) {
            minDistance = min(minDistance, TSP(n, j, mask | (1 << j)) + graph[i][j]);
        }
    }
    return iMem[mask][i] = minDistance;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j= 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < (1 << N); ++i) fill(iMem[i], iMem[i] + N, -1);
    printf("%d\n", TSPBitmaskDP(n, graph));
    printf("%d\n", TSP(n, 0, 1));

}
// tsp sample test case
// 6
