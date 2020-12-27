#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	int t, n, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		unordered_map<int, vector<int>> subsets;
		vector<int> num;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			num.push_back(x);
		}

		bool notfound = true;
		for (int msk = 0; msk < (1 << n); msk++) {
			int s = 0;
			vector<int> elements;
			for (int j = 0; j < n; j++) {
				if (msk & (1 << j)) {
					elements.push_back(num[j]);
					s += num[j];
				}		
			}

			if (subsets.find(s) != subsets.end()) {
				cout << "Case #" << i + 1 << ":\n";
				for (auto item : subsets[s])
					cout << item << " ";
				cout << endl;
				for (auto item : elements)
					cout << item << " ";
				cout << endl;
				notfound = false;
				break;
			}
			else {
				subsets[s] = elements;
			}
		}

		if (notfound) {
			cout << "Case #" << i + 1 << ":\n";
			cout << "Impossible" << endl;
		}
	}

	return 0;
}