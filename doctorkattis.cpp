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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t, level, cnt = 0;
	cin >> n;
	string name;
	multiset<tuple<int, int, string>> cats;
	map<string, multiset<tuple<int, int, string>>::iterator> pointers;
	multiset<tuple<int, int, string>>::iterator it;
	while (n--) {
		cin >> t;
		if (t == 0) {
			cin >> name >> level;
			level = -level;
			it = cats.insert({level, cnt, name});
			pointers[name] = it;
			cnt++;
		}else if (t == 1) {
			cin >> name >> level;
			int cur_level, cur_order;
			tie(cur_level, cur_order, name) = *pointers[name];
			cats.erase(pointers[name]);
			it = cats.insert({-level+cur_level, cur_order, name});
			pointers[name] = it;
		} else if (t == 2) {
			cin >> name;
			cats.erase(pointers[name]);
			pointers.erase(name);
		} else {
			int order;
			if (cats.empty()) cout << "The clinic is empty\n";
			else {
				tie(level, order, name) = *cats.begin();
				cout << name << '\n';
			}

		}
	}

	return 0;
}
