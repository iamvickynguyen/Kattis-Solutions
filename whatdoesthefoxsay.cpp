#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;

int main() {
	int t;
	string line, word;
	cin >> t;
	getline(cin, line);
	for (int i = 0; i < t; i++) {
		vector<string> sounds;
		unordered_set<string> set;
		getline(cin, line);
		stringstream ss(line);
		getline(cin, line);
		while (line != "what does the fox say?") {
			stringstream stream(line);
			stream >> word >> word >> word;
			set.insert(word);
			getline(cin, line);
		}
		while (ss >> word) {
			if (set.find(word) == set.end())
				cout << word << " ";
		}
		cout << endl;
	}
	
	return 0;
}