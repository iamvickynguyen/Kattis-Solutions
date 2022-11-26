#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

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

int main() {
	int n, k, a, b;
	cin >> n >> k;

	UF uf(n);
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		--a, --b;
		uf.union_set(a, b);
	}

	bool ok = true;
	for (int i= 0; i < n/2; ++i) {
		if (!uf.same_set(i, n - i - 1)) {
			ok = false;
			cout << "No";
			break;
		}
	}

	if (ok) cout << "Yes";
}
