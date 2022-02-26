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

ll merge(string &s, vll &ans, int left, int mid, int right) {
    ll inv_count = 0;
    int i = left, j = mid, k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (s[i] - '0' <= s[j] - '0') ans[k++] = 1LL * s[i++] - '0';
        else {
            ans[k++] = 1LL * s[j++] - '0';
            inv_count += 1LL * (mid - i);
        }
    }

    while (i <= mid - 1) ans[k++] = 1LL * s[i++] - '0';
    while (j <= right) ans[k++] = 1LL * s[j++] - '0';
    for (i = left; i <= right; i++) s[i] = ans[i] + '0';
    return inv_count;
}

ll mergesort(string &s, vll &ans, int left, int right) {
    int mid;
    ll inv_count = 0;
    if (right > left) {
        mid = (right + left)/2;
        inv_count = mergesort(s, ans, left, mid);
        inv_count += mergesort(s, ans, mid + 1, right);
        inv_count += merge(s, ans, left, mid + 1, right);
    }
    return inv_count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vll ans(s.length());
    cout << mergesort(s, ans, 0, s.length() - 1);

    return 0;
}