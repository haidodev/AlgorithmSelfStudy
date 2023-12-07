// TAG: Bitmask DP
// Link: https://cses.fi/problemset/task/1690
// n city, m one-way flights between those n city, count the number of flight start from 1 
// and end in n, flight through all the cities
#include <iostream>
#define N 20
#define MOD 1000000007

int isConnected[N][N] = {false};
int dp[N][1 << N] = {0}, n;
// int Hamiltonian(int curPos, int mask) {
//     // printf("%d ", curPos);
//     if (((1 << (n - 1)) - 1) == mask && isConnected[curPos][n - 1]) return isConnected[curPos][n - 1];
//     long long res = 0;
//     for (int i = 1; i < n - 1; ++i) { 
//         if ((1 << i) & mask) continue;
//         if (!isConnected[curPos][i]) continue;
//         res += 1LL * Hamiltonian(i, 1 << i | mask) * isConnected[curPos][i];
//         res %= MOD;
//     }
//     return res;
// }

// Above is the preivous implementation, got TLE. probably becase using Recursive implementation
int Hamiltonian() {
    dp[0][1] = 1;
    for (int mask = 3; mask < 1 << (n - 1); mask += 2) {
        for (int end = 1; end < n - 1; ++end) {
            if ((mask & (1 << end)) == 0) continue;
            int prev = mask - (1 << end);
            long long int tmp = 0;
            for (int start = 0; start < n - 1; ++start) {
                if ((prev & (1 << start)) == 0 || isConnected[start][end] == 0) continue;
                tmp += 1LL * isConnected[start][end] * dp[start][prev];
                tmp %= MOD;
            } 
            dp[end][mask] = tmp;
        }   
    }
    long long int res = 0;
    for (int start = 0; start < n - 1; ++start) {
        res += isConnected[start][n - 1] * dp[start][(1 << (n - 1))- 1];
        res %= MOD;
    }
    return res;
}

// This one using Iterative approach:
/*
It's seem that the standard implementation was the biggest loop was iterate through all 
the mask (2^N), then iterate through each element, then each element in the inner-loop

dp[end][mask] count number of route  fly over all cities in "mask", and end in "end" 
DP function dp[i][S] = sum of all dp[x][S \ {i}] for all x belong to adj[i]


for this problem, since the bit represent the 1st city is alway 1, so it's no good iterative odd mask,
that why the step used in this problem is 2

then in the second loop, loop though all the set bit in the mask and choose that to be the end point 
for this mask

lastly, the last loop, loop through all bit set, check if this start connected with the end, if so
add this to the current count, note that S \ {x} = mask - (1 << end)
*/
int main() {
    int m;
    scanf("%d%d", &n, &m);
    while (m--) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        ++isConnected[src - 1][dest - 1];
    }
    printf("%d", Hamiltonian());

}

/*
4 6
1 2
1 3
2 3
3 2
2 4
3 4
*/