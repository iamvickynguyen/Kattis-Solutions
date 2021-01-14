#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int hash_func(string s) {
	int result = 0;
	for (auto c : s) {
		result ^= c;
	}
	return result;
}

int combinations(int n) {
	return n * (n - 1) / 2;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin.ignore();
	while (n) {
		unordered_map<string, int> um;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			um[s] ++;
		}

		unordered_map<int, vector<string>> hash_um;
		for (auto item : um) {
			hash_um[hash_func(item.first)].push_back(item.first);
		}

		int collisions = 0;
		for (auto item : hash_um) {
			int total = 0;
			for (auto st : item.second) {
				total += um[st];
				collisions -= combinations(um[st]);
			}

			collisions += combinations(total);
		}

		cout << um.size() << " " << collisions << endl;

		cin >> n;
		cin.ignore();
	}
	return 0;
}