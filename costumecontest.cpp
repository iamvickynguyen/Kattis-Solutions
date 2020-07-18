#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	unordered_map<string, int> um;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (um.find(s) != um.end())
			um[s] += 1;
		else
			um[s] = 1;
	}

	vector<pair<string, int>> costumes;
	for (pair<string, int> c : um)
		costumes.push_back(c);
	sort(costumes.begin(), costumes.end(), [](pair<string, int> elem1, pair<string, int> elem2)
	{
		return elem1.second < elem2.second;
	});

	vector<string> result;
	int min = costumes[0].second;
	for (auto c : costumes) {
		if (c.second == min)
			result.push_back(c.first);
		else
			break;
	}
	sort(result.begin(), result.end());
	for (string s : result)
		cout << s << '\n';
	return 0;
}