#include <iostream>
#include <vector>
#define N 1001
int graph[N][N];
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &graph[i][j]);
        } 
    }
    int m;
    scanf("%d", &m);
    int staringPoint, totalDistance = 0;
    scanf("%d", &staringPoint);
    while (m-- > 1) {
        int nextPoint;
        scanf("%d", &nextPoint);
        totalDistance += graph[staringPoint][nextPoint];
        staringPoint = nextPoint;
    }
    printf("%d", totalDistance);
    return 0;
}