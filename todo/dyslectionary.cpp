#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void print_output(vector<string>& dyslectionary) {
	sort(dyslectionary.begin(), dyslectionary.end(),
			[](const string &a, const string &b) {
				const int len_a = a.length();
				const int len_b = b.length();
				if (a[len_a - 1] < b[len_b - 1]) return true;
				else if (a[len_a - 1] > b[len_b - 1]) return false;
				return len_a < len_b;			
	});

	for (auto& s: dyslectionary)
		cout << s << '\n';
}

int main() {
	string s;
	vector<string> dyslectionary;
	while (getline(cin, s)) {
		if (s == "") {
			print_output(dyslectionary);
			cout << endl;
			dyslectionary.clear();
		} else {
			dyslectionary.push_back(s);
		}
	}

	print_output(dyslectionary);
	return 0;
}
