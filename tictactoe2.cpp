#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

unordered_set<string> ans;
string board = ".........";

bool is_ended() {
	// horizontal
	for (int i = 0; i < 3; i++) {
		int x = 0, o = 0;
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] == 'X') x++;
			else if (board[i * 3 + j] == 'O') o++;
		}
		if (x == 3 || o == 3) return true;
	}

	// vertical
	for (int i = 0; i < 3; i++) {
		int x = 0, o = 0;
		for (int j = 0; j < 3; j++) {
			if (board[i + j * 3] == 'X') x++;
			else if (board[i + j * 3] == 'O') o++;
		}
		if (x == 3 || o == 3) return true;
	}

	// left diagonal
	int x = 0, o = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i * 3 + i] == 'X') x++;
		else if (board[i * 3 + i] == 'O') o++;
	}
	if (x == 3 || o == 3) return true;

	// right diagonal
	x = 0, o = 0;
	for (int i = 2; i >= 0; i--) {
		if (board[i + (2 - i) * 3] == 'X') x++;
		else if (board[i + (2 - i) * 3] == 'O') o++;
	}
	if (x == 3 || o == 3) return true;

	return false;
}

void generate(int row, int col, bool turn) {
	ans.insert(board);
	if (is_ended()) return;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i * 3 + j] == '.') {
				board[i * 3 + j] = (turn) ? 'X' : 'O';
				generate(i, j, !turn);
				board[i * 3 + j] = '.';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	generate(0, 0, true);
	int n;
	cin >> n;
	cin.ignore();
	string s, row;
	for (int i = 0; i < 3; i++) {
		getline(cin, row);
		s += row;
	}
	cout << ((ans.count(s) > 0) ? "yes\n" : "no\n");
	n--;

	while (n--) {
		getline(cin, row);
		s = "";
		for (int i = 0; i < 3; i++) {
			getline(cin, row);
			s += row;
		}

		cout << ((ans.count(s) > 0) ? "yes\n" : "no\n");
	}

	return 0;
}
