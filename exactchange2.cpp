#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

void coin_change(int price, vi &v) {
    int inf = 100002, maxW = price + *max_element(all(v)) + 1;
    vi dp(maxW, inf);
    dp[0] = 0;
    for (auto &coin: v) {
        for (int i = maxW - 1; i >= 0; i--) {
            if (dp[i] != inf && (i + coin) < maxW) dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }

    for (int i = price; i < maxW; i++) {
        if (dp[i] != inf) {
            cout << i << " " << dp[i] << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, price, n;
    cin >> t;
    while (t--) {
        cin >> price;
        cin >> n;
        vi v(n);
        for (auto &x: v) cin >> x;
        coin_change(price, v);
    }

    return 0;
}
