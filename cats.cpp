#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

class UF {
    private:
        vi parent, rank;
    public:
        UF(int N) {
            parent.assign(N, 0);
            for (int i = 0; i < N; i++) parent[i] = i;
            rank.assign(N, 0);
        }

        int find(int v) {
            if (parent[v] != v) parent[v] = find(parent[v]);
            return parent[v];
        }

        bool same_set(int a, int b) {
            return find(a) == find(b);
        }

        void union_set(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (rank[ra] < rank[rb]) swap(ra, rb);
            parent[rb] = ra;
            if (rank[ra] == rank[rb]) rank[ra]++;
        }
};

bool kruskal(vector<tuple<int, int, int>> &graph, int n, int bound) {
    sort(all(graph));
    UF uf(n);

    int cost = 0;
    int cnt = 0;
    for (int i = 0; i < graph.size(); i++) {
        int w, u, v;
        tie (w, u, v) = graph[i];
        if (!uf.same_set(u, v)) {
            cost += w;
            uf.union_set(u, v);
            cnt++;

			if (cost >= bound) return false;
			if (cnt == n - 1) return cost + n <= bound;
        }
    }

    return cost + n <= bound;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, m, c, u, v, w;
	cin >> t;
	while (t--) {
		vector<tuple<int, int, int>> graph;
		cin >> m >> c;
		for (int i = 0; i < c*(c - 1)/2; i++) {
			cin >> u >> v >> w;
			graph.pb({w, u, v});
		}

		bool ok = kruskal(graph, c, m);
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}
 
    return 0;
}