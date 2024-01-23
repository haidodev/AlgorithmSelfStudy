#include <iostream>
#include <queue>
#include <string>
using namespace std;

void minString(string s, int k) {
    deque<char> q;
    int left = s.size() - k;
    for (int i = 0; i < left; ++i) {
        while (!q.empty() && s[q.back()] <= s[i]) q.pop_back();
        q.push_back(i);
    }
    while (k--) {
        while (!q.empty() && s[q.back()] <= s[left]) q.pop_back();
        q.push_back(left);
        cout << s[q.front()];
        q.pop_front();
        ++left;
    }
}
int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    minString(s, k);
}