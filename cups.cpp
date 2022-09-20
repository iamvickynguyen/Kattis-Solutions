#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool is_number(string s) {
	return all_of(s.begin(), s.end(), [](char c) { return isdigit(c); });
}

int main() {
	int n;
	cin >> n;
	string a, b;
	vector<pair<int, string>> cups;
	cups.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (is_number(a)) {
			int r = (stoi(a) + 0.0) / 2;
			cups.push_back({r, b});
		} else {
			cups.push_back({stoi(b), a});
		}
	}
	sort(cups.begin(), cups.end());
	for (auto &[r, cup]: cups)
		cout << cup << '\n';
	return 0;
}
