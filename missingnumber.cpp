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

int len(int num) {
    int cnt = 0;
    while (num > 0) {
        num /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int expected = 1, i = 0;
    bool ok = false;
    while (i < s.size()) {
        int l = len(expected);
        int cur = 0;
        for (int j = 0; j < l; j++) {
            int x  = s[i] - '0';
            cur = cur * 10 + x;
            i++;
        }

        if (expected != cur) {
            cout << expected;
            ok = true;
            break;
        }

        expected++;
    }

    if (!ok) cout << expected;

    return 0;
}