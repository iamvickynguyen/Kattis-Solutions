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

bool is_collinear(pii a, pii b, pii c) {
    return (a.first - b.first) * (a.second - c.second) == (a.first - c.first) * (a.second - b.second);
}

int nC3(int n) {
    return (n * (n - 1) * (n - 2))/6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    
    string s;
    vector<pii> coords;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < n; j++) {
            if (s[j] != '.') coords.pb({i, j});
        }
    }

    int points_count = coords.size();
    vvi table(points_count, vi(points_count, 0));
    ll ans = 0;
    for (int i = 0; i < points_count; i++) {
        for (int j = i + 1; j < points_count; j++) {
            if (table[i][j] == 0) {
                vi points = {i, j};
                for (int k = j + 1; k < points_count; k++) {
                    if (is_collinear(coords[i], coords[j], coords[k])) points.pb(k);
                }

                if (points.size() > 2) {
                    for (int p = 0; p < points.size(); p++) {
                        for (int q = 0; q < points.size(); q++) {
                            table[points[p]][points[q]] = 1;
                            table[points[q]][points[p]] = 1;
                        }
                    }  
                    ans += 1LL * nC3(points.size());
                }
            }
        }
    }

    cout << ans;
    return 0;
}