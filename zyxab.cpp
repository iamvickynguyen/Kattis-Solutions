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

const string inf = "aaaaaaaaaaaaaaaaaaaaaaa";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string ans = inf, s;
    while (n--) {
        cin >> s;
        if (s.length() >= 5 && ans.length() >= s.length()) {
            bool ok = true;
            vi seen(26, 0);
            for (auto &c : s) {
                int num = int(c) - 97;
                if (seen[num] == 1) {
                    ok = false;
                    break;
                }

                seen[num] = 1;
            }

            if (ok) {
                if (ans.length() == s.length()) ans = max(ans, s);
                else ans = s;
            }
        }
    }

    if (ans != inf) cout << ans;
    else cout << "neibb!";
    
    return 0;
}
