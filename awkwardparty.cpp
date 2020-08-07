#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    unordered_map<int, vector<int>> um;
    for (int i = 0; i < n; i++) {
        cin >> x;
        um[x].push_back(i);
    }

	int level = n;
    for (auto guest : um) {
        vector<int> g = guest.second;
        for (int i = 0; i < g.size() - 1; i++) {
            level = min(level, g[i + 1] - g[i]);
        }
    }

    cout << level << endl;
    return 0;
}