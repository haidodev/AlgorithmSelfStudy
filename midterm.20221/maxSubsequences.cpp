#include<iostream>
#define MAX_N 100000
using namespace std;
int maxSubsequences(int arr[MAX_N], int n) {
    // int dp[MAX_N][3];
    // dp[0][0] = 0;
    // dp[0][1] = arr[0];
    // dp[0][2] = arr[0];
    int prev[3] = {0, arr[0], arr[0]};
    for (int i = 1; i < n; ++i) {
        int tmp[3] = {prev[0], prev[1], prev[2]};
        // dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1],dp[i - 1][2]));
        // dp[i][1] = dp[i - 1][0] + arr[i];
        // dp[i][2] = dp[i - 1][1] + arr[i];
        prev[0] = max(tmp[0], max(tmp[1], tmp[2]));
        prev[1] = tmp[0] + arr[i];
        prev[2] = tmp[1] + arr[i];
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    }
    return max(prev[0], max(prev[1], prev[2]));
    // return max(dp[n - 1][0], max(dp[n - 1][1],dp[n - 1][2]));
}
int main(){
    int n, arr[MAX_N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }
    printf("%d", maxSubsequences(arr, n));
}
/*
7
4 10 6 6 6 2 5
*/