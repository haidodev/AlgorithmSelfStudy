#include <iostream>
#include <algorithm>
#include <climits> // For boundary
#include <vector>
#include <queue>
#include <numeric> // accumulate
#include <utility> // pair
using namespace std;

template <typename T>
using mat = std::vector<std::vector<T>>;

// Function to initialize a matrix with a specific number of rows and columns
template <typename T>
mat<T> matInit(int rows, int cols, const T& initialValue = T()) {
    return mat<T>(rows, std::vector<T>(cols, initialValue));
}

// CATEGORY: Printing VECTOR

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void printVec(vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << "\n";
}
void printMat(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); ++i)
        printVec(v[i]);
}
int maxElm(vector<int> v)
{
    // accumulate(v.begin(), v.end(), 0, [](int a, int b)
    //            { return max(a, b); });
    int maxELm = v[0];
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        maxELm = max(maxELm, *it);
    }
    return maxELm;
}
// CATEGORY: Binary Search
int lowerBound(const int arr[], int size, int target)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

// Custom implementation of upper_bound
int upperBound(const int arr[], int size, int target)
{
    int left = 0;
    int right = size;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}
// built-in sorting function
bool reverseSorting(int a, int b)
{
    return a > b; // Change to a < b for ascending order
}
void SortingFunction()
{
    int arr[] = {5, 2, 9, 1, 7};

    int size = sizeof(arr) / sizeof(arr[0]);

    // Lambda: WORKING OR NOT
    // sort(arr, arr + size, [](int a, int b)
    //      {
    //          return a > b; // Change to a < b for ascending order
    //      });
    sort(arr, arr + size, reverseSorting);

    cout << "Sorted array in descending order: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
}

void sampleIO()
{
    freopen("sample_inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cout << "Case #" << t << ": ";
    }
}

int maxNumInRange()
{
    int arr[] = {14, 7, 5, 14, 0, 17, 2, 9, 10, 19, 8, 2, 13, 12, 10, 7, 7, 4, 11, 1}, n = 20, l = 3;

    deque<int> mono;
    for (int i = 0; i < n; ++i)
    {
        if (!mono.empty() && mono.front() + l < i)
            mono.pop_front();
        while (!mono.empty() && arr[mono.back()] <= arr[i])
            mono.pop_back();
        mono.push_back(i);
        if (i >= l)
            printf("MAX([%d, %d]) = %d\n", i - l, i, arr[mono.front()]);
    }
}
int LongestIncreasingSubsequences()
{
    int arr[] = {14, 7, 5, 14, 0, 17, 2, 9, 10, 19, 8, 2, 13, 12, 10, 7, 7, 4, 11, 1}, n = 20;
    vector<int> dp;
    for (int i = 0; i < n; ++i)
    {
        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end())
            dp.push_back(arr[i]);
        else
            *it = arr[i];
    }
    return dp.size();
}
int LongestCommonSubstring()
{
    string s1 = "hofubmnylkra", s2 = "pqhgxgdofcvmr";
    vector<int> dp(s1.size(), 0);
    for (int i = 0; i < s2.size(); ++i)
    {
        int tmp = dp[0];
        dp[0] = max(dp[0], int(s1[0] == s2[i]));
        for (int j = 1; j < s1.size(); ++j)
        {
            int tmpDP = dp[j];
            if (s2[i] == s1[j])
                dp[j] = tmp + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            tmp = tmpDP;
        }
    }
    return dp.back();
}
int Knapsack(const std::vector<int>& weights, const std::vector<int>& values, int capacity)
{
    int n = weights.size();

    // Create a 2D table to store the results of subproblems
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    // Fill the dp table using bottom-up dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is in the bottom-right cell of the dp table
    return dp[n][capacity];
}
int main()
{
    cout << LongestCommonSubstring();
}
