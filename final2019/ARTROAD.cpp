#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
struct Interval {
    int start, end;
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
    bool operator<(const Interval& other) {
        return end < other.end;
    }
};
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Interval> intervals(m);
    for (int i = 0; i < m; ++i) {
        int start, end;
        scanf("%d %d", &start, &end);
        intervals[i] = Interval(start, end);
    } 
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            
        }
    }
}