#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	string s, english, foreign;
	getline(cin, s);
	unordered_map<string, string> dict;
	while (!s.empty()) {
		stringstream line(s);
		line >> english >> foreign;
		dict[foreign] = english;
		getline(cin, s);
	}

	while (cin >> s) {
		if (dict.find(s) == dict.end())
			cout << "eh" << endl;
		else
			cout << dict[s] << endl;
	}

	return 0;
}