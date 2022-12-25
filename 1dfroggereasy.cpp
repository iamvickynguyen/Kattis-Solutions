#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, s, m;
	cin >> n >> s >> m;
	--s;

	vector<int> board(n), seen(n, 0);
	for (auto &x: board) cin >> x;

	int count = 0;
	while (true) {
		if (seen[s] == 1) {
			cout << "cycle\n" << count;
			break;
		}

		if (board[s] == m) {
			cout << "magic\n" << count;
			break;
		}
		
		if (s < 0) {
			cout << "left\n" << count;
			break;
		}

		if (s >= n) {
			cout << "right\n" << count;
			break;
		}

		seen[s] = 1;
		s += board[s];
		++count;
	}
	return 0;
}
