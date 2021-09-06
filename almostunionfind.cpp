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

ii parent, size_set;
unordered_map<int, ll> sum_set;

void make_set(int n) {
    for (int i = 1, j = n + 1; i <= n; i++, j++) {
        parent[i] = j;
        parent[j] = j;
        size_set[j] = 1;
        sum_set[j] = i;
    }
}

int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
}

void union_set(int p, int q) {
    int rp = find(p), rq = find(q);
    if (rp == rq) return;
    if (size_set[rp] < size_set[rq]) swap(rp, rq);
    parent[rq] = rp;
    size_set[rp] += size_set[rq];
    sum_set[rp] += sum_set[rq];
}

void move(int p, int q) {
    int rp = find(p), rq = find(q);
    if (rp == rq) return;

    size_set[rp]--;
    size_set[rq]++;
    sum_set[rq] += 1LL * p;
    sum_set[rp] -= 1LL * p;
    parent[p] = rq;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, k, p, q;
    while (cin >> n >> m) {
        parent.clear();
        size_set.clear();
        sum_set.clear();
        make_set(n);

        for (int i = 0; i < m; i++) {
            cin >> k;
            if (k == 1) {
                cin >> p >> q;
                union_set(p, q);
            } else if (k == 2) {
                cin >> p >> q;
                move(p, q);
            } else {
                cin >> p;
                int root = find(p);
                cout << size_set[root] << " " << sum_set[root] << '\n';
            }
        }
    }

	return 0;
}
