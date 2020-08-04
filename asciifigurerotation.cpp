#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;

// stackoverflow
static inline string& rtrim(string& s)
{
	s.erase(find_if_not(s.rbegin(), s.rend(), [](int c) {return isspace(c); }).base(), s.end());
	return s;
}

int main() {
	int n, max_col = 0;
	string line;
	bool first = true;
	cin >> n;
	cin.ignore();
	while (n) {
		if (!first)
			cout << endl;
		vector<string> figure;
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			figure.push_back(line);
			if (max_col < line.size())
				max_col = line.size();
				//max_col = max(max_col, line.size());
		}

		vector<vector<char>> rotation(max_col, vector<char>(n, ' '));
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < figure[r].size(); c++) {
				if (figure[r][c] == '|')
					rotation[c][r] = '-';
				else if (figure[r][c] == '-')
					rotation[c][r] = '|';
				else
					rotation[c][r] = figure[r][c];
			}
		}

		for (int r = 0; r < max_col; r++) {
			string out = "";
			for (int c = n - 1; c >= 0; c--) {
				out += rotation[r][c];
			}
			string res = rtrim(out);
			if (res != "")
				cout << res << endl;
		}
		first = false;
		cin >> n;
		cin.ignore();
	}
	return 0;
}