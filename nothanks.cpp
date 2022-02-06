#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back
// #define TIME

const int maxn = 90002;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, x;
    cin >> n;
    vi v(maxn, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x] = 1;
    }

    int ans = 0;
    int i = 1;
    while (i < maxn) {
        while (i < maxn && v[i] == 0) i++;
        if (i < maxn && v[i] == 1) {
            ans += i;
        }
        while (i < maxn && v[i] == 1) i++;
    }

    cout << ans;

	#ifdef TIME
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    #endif

    return 0;
}