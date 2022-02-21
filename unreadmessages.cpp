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
typedef priority_queue<int> pq;
#define all(x) (x).begin(), (x).end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m;
    ll unread = 0;
    unordered_map<int, ll> senders;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        ll read = 1LL * i - senders[x] - 1;
        unread += 1LL * (n - 1) - read;
        senders[x] = 1LL * i;
        cout << unread << '\n';
    }

    return 0;
}