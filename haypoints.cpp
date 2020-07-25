#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> um;
	int m, n, v;
	cin >> m >> n;

	string s;
	for (int i = 0; i < m; i++) {
		cin >> s >> v;
		um[s] = v;
	}

	for (int i = 0; i < n; i++) {
		int result = 0;
		cin >> s;
		while (s != ".") {
			if (um.find(s) != um.end())
				result += um[s];
			cin >> s;
		}

		cout << result << endl;
	}

	return 0;
}