#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_output(vector<string>& dyslectionary, const int maxlength) {
	sort(dyslectionary.begin(), dyslectionary.end());

	for (auto& s: dyslectionary) {
		for (int i = 0; i < (maxlength - s.length()); ++i)
			cout << " ";

		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}

int main() {
	string s;
	vector<string> dyslectionary;
	int maxlength = 0;
	while (getline(cin, s)) {
		if (s == "") {
			print_output(dyslectionary, maxlength);
			cout << endl;
			maxlength = 0;
			dyslectionary.clear();
		} else {
			reverse(s.begin(), s.end());
			dyslectionary.push_back(s);
			maxlength = max(maxlength, (int)s.length());
		}
	}

	print_output(dyslectionary, maxlength);
	return 0;
}
