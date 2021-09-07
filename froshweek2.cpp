#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vi tasks(n), intervals(m);
    for (int i = 0; i < n; i++) cin >> tasks[i];
    for (int i = 0; i < m; i++) cin >> intervals[i];
    sort(all(tasks));
    sort(all(intervals));

    int ans = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (intervals[i] >= tasks[ans]) ans++;
    }

    cout << ans;
	return 0;
}
