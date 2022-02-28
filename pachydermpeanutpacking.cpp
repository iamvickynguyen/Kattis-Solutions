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

struct box {
	double x1, y1, x2, y2;
	string type;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	while (n != 0) {
		vector<box> boxes;
		double x1, y1, x2, y2;
		string type;
		for (int i = 0; i < n; i++) {
			cin >> x1 >> y1 >> x2 >> y2 >> type;
			struct box b = {x1, y1, x2, y2, type};
			boxes.pb(b);
		}
		sort(all(boxes), [](const box &a, const box &b) {
			if (a.x1 == b.x1) {
				if (a.x2 == b.x2) return a.y1 < b.y1;
				return a.x2 < b.x2;
			}
			return a.x1 < b.x1;
		});

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x1 >> y1 >> type;
			bool flag = false;
			for (auto &b: boxes) {
				if (x1 >= b.x1 && x1 <= b.x2 && y1 >= b.y1 && y1 <= b.y2) {
					if (type == b.type) cout << type << " correct\n";
					else cout << type << " " << b.type << '\n';
					flag = true;
					break;
				}
			}
			if (!flag) cout << type << " floor\n";
		}

		cout << '\n';
		cin >> n;
	}

	return 0;
}
