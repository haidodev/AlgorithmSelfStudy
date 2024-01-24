#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    int nums[5001];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (i == nums[nums[nums[i]]]) {
            printf("YES");
            return 0;
        }
    } 
    printf("NO");
}