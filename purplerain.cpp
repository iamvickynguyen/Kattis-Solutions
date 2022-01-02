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

tuple<int, int, int> kadane(bool flag, string &s) {
	int ans = 0, sum = 0, start = 0, end = 0, restart = 0;
	for (int i = 0; i < s.length(); i++) {
		int num = (s[i] == 'B') ? 1 : -1;
		if (flag) num = -num;

		if (sum + num < 0) {
			sum = 0;
			restart = i + 1;
		} else {
			sum += num;
		}

		if (sum > ans) {
			ans = sum;
			start = restart;
			end = i;
		}
	}

	return {ans, start, end};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int ans1, start1, end1, ans2, start2, end2;
	tie(ans1, start1, end1) = kadane(true, s);
	tie(ans2, start2, end2) = kadane(false, s);

	if (ans1 == ans2) {
		if (end1 < end2) cout << start1 + 1 << " " << end1 + 1 << '\n';
		else cout << start2 + 1 << " " << end2 + 1 << '\n';
	} else if (ans1 > ans2) cout << start1 + 1 << " " << end1 + 1 << '\n';
	else cout << start2 + 1 << " " << end2 + 1 << '\n';

	return 0;
}
