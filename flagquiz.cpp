#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	
	int n;
	cin >> n;
	cin.ignore();
	string token;

	vector<vector<string>> answers;
	for (int i = 0; i < n; ++i) {
		getline(cin, line);
		stringstream ss(line);
		vector<string> flags;
		while (getline(ss, token, ',')) {
			flags.push_back(token);
		}
		answers.push_back(flags);
	}

	const int len = answers[0].size();
	vector<int> max_changes(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				int count = 0;
				for (int k = 0; k < len; ++k) {
					if (answers[i][k] != answers[j][k])
						++count;
				}
				max_changes[i] = max(max_changes[i], count);
			}
		}
	}

	const int min_val = *min_element(max_changes.begin(), max_changes.end());
	for (int i = 0; i < n; ++i) {
		if (max_changes[i] == min_val) {
			cout << answers[i][0];
			for (int j = 1; j < len; ++j) {
				cout << "," << answers[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
