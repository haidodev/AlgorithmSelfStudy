#include <iostream>
#define N 20
#define M 1001
#define K 11
using namespace std;
int KCombination(int arr[N], int n, int m, int k)
{
    int dp[M][K] = {0};
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int s = m - arr[i]; s >= 0; --s)
        {
            for (int l = k - 1; l >= 0; --l)
            {
                dp[s + arr[i]][l + 1] += dp[s][l]; // loop backward since this dp function may be affected in the previous change if loop forward
            }
        }
        // cout << "------------------" << endl;

        // for (int i = 0; i <= m; ++i)
        // {
        //     for (int j = 0; j <= k; ++j)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    return dp[m][k];
}
int main()
{
    int arr[N], n, m, k;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);
    }
    printf("%d", KCombination(arr, n, m, k));
}
/*
5 3 10
1 2 3 4 5
*/