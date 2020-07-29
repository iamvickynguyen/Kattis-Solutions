#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, c;
	cin >> n;
	map<vector<int>, int> frequencies;
	for (int i = 0; i < n; i++) {
		vector<int> line;
		for (int j = 0; j < 5; j++) {
			cin >> c;
			line.push_back(c);
		}
		sort(line.begin(), line.end());
		frequencies[line]++;
	}

	int _max = 0;
	for (auto combination : frequencies) {
		_max = max(combination.second, _max);
	}

	int total = 0;
	for (auto combination : frequencies) {
		total = total + (combination.second == _max ? _max : 0);
	}

	cout << total << endl;
	return 0;
}