#include <iostream>
#include <vector>
#include <algorithm>
#define N 1000
using namespace std;
int main() {
    int height[N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n ;++i) {
        scanf("%d", &height[i]);
    }
    sort(height, height + n);
    int dp[3] = {0};
    for (int i = 0; i < n; ++i) {
        int current = 1 + dp[0];
        if (i > 0 && abs(height[i] - height[i - 1]) <= 20) current = min(current, 1 + dp[1]); 
        if (i > 1) {
            int minH = min(height[i], min(height[i - 1], height[i - 2])),
                maxH = max(height[i], max(height[i - 1], height[i - 2]));
            if (maxH - minH <= 10) current = min(current, 1 + dp[2]);
        }
        dp[2] = dp[1];
        dp[1] = dp[0];
        dp[0] = current;
    }
    printf("%d", dp[0]);
    return 0;
}