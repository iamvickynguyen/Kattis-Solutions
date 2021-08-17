#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
#define az(x) (x).begin(), (x).end()

int binsearch(vector<ll> &v, ll num) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int mid = (l + r)/2;
        if (v[mid] == num) {
            return mid;
        }

        if (v[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    ll m, a, c, x;
    cin >> n >> m >> a >> c >> x;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        x = (a * x + c) % m;
        v.push_back(x);
    }

    int cnt = 0;
    for (auto num : v) {
        int pos = binsearch(v, num);
        if (v[pos] == num) cnt++;
    }
    cout << cnt;

	return 0;
}
