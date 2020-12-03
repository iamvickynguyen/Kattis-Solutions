#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, votes, total = 0, maxvote = -1, index = -1, countequal = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> votes;
			if (votes == maxvote) {
				countequal++;
			}
			else if (votes > maxvote) {
				maxvote = votes;
				index = i;
				countequal = 1;
			}
			total += votes;
		}

		if (total / 2 < maxvote) {
			cout << "majority winner " << index + 1 << endl;
		}
		else {
			if (countequal > 1)
				cout << "no winner" << endl;
			else
				cout << "minority winner " << index + 1 << endl;
		}
	}

	return 0;
}