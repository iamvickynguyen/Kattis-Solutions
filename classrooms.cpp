#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k, s, f;
    cin >> n >> k;
    vector<pii> activities;
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        activities.pb({f, s}); // sort by ending time
    }

    sort(all(activities));

    int cnt = 0;
    multiset<int> ends;
    for (int i = 0; i < k; i++) ends.insert(0);
    for (auto a : activities) {
        auto pos = ends.upper_bound(a.second);
        if (pos != ends.begin()) {
            ends.erase(prev(pos));
            ends.insert(a.first + 1);
            cnt++;
        }
    }

    cout << cnt;
	return 0;
}
