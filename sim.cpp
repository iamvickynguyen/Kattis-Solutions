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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		list<char> ans;
		list<char>::iterator it = ans.begin();
		for (char c: s) {
			if (c == '<') {
				if (it != ans.begin()) it = ans.erase(--it);
			}
			else if (c == '[') it = ans.begin();
			else if (c == ']') it = ans.end();
			else it = ans.insert(it, c), it++;
		}

		for (char x : ans) cout << x;
		cout << '\n';
	}

	return 0;
}
