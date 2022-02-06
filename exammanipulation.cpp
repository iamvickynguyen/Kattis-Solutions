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

vector<vector<char>> keys;
vector<char> tmp;

void generate_ans(int i, int k) {
    if (i == k) {
        keys.pb(tmp);
        return;
    }

    tmp.pb('T');
    generate_ans(i + 1, k);
    tmp.pop_back();

    tmp.pb('F');
    generate_ans(i+1, k);
    tmp.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    cin.ignore();
    vector<string> students(n);
    for (auto &s: students) getline(cin, s);

    generate_ans(0, k);

    int ans = 0;
    for (auto &key: keys) {
        int allwrongans = 0;
        for (auto &st: students) {
            int wrongans = 0;
            for (int i = 0; i < k; i++) {
                if (st[i] != key[i]) wrongans++;
            }

            allwrongans = max(allwrongans, wrongans);
        }

        ans = max(ans, k - allwrongans);
    }

    cout << ans;

    return 0;
}