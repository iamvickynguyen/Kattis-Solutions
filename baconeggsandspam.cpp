#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		string line, name, order;
		cin.ignore();
		map<string, vector<string>> orders;
		for (int i = 0; i < n; ++i) {
			getline(cin, line);
			istringstream ss(line);
			getline(ss, name, ' ');
			while (getline(ss, order, ' ')) {
				orders[order].push_back(name);
			}
		}

		for (auto& [o, names]: orders) {
			cout << o << " ";
			sort(names.begin(), names.end());
			for (auto& u: names)
				cout << u << " ";
			cout << '\n';
		}

		cout << '\n';
	}


	return 0;
}
