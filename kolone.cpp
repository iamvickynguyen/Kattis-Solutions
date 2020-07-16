#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void swap(vector<char> &ants, int i, unordered_set<char> &right_ants) {
	if (i - 1 >= 0 && right_ants.find(ants[i - 1]) == right_ants.end()) {
		int tmp = ants[i];
		ants[i] = ants[i - 1];
		ants[i - 1] = tmp;
	}
}

int main() {
	int n1, n2, t;
	string r1, r2;
	vector<char> ants;
	unordered_set<char> right_ants;
	cin >> n1 >> n2 >> r1 >> r2 >> t;
	for (int i = n1 - 1; i >= 0; i--)
		ants.push_back(r1[i]);
	for (int i = 0; i < n2; i++) {
		ants.push_back(r2[i]);
		right_ants.insert(r2[i]);
	}

	int cur = n1;
	while (t > 0) {
		vector<int> positions_to_swap = { cur };
		for (int i = cur + 1; i < ants.size(); i++) {
			if (right_ants.find(ants[i]) != right_ants.end()) {
				if (i - 1 >= 0 && right_ants.find(ants[i - 1]) == right_ants.end())
					positions_to_swap.push_back(i);
			}
		}
		for (int p : positions_to_swap)
			swap(ants, p, right_ants);
		cur = cur - 1 >= 0 ? cur - 1 : 0;
		t--;
	}
	for (char a : ants)
		cout << a;
		
	return 0;
}
