#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void print_recursively(vector<vector<int>> &graph, int v, vector<string> &words) {
	cout << words[v];
	for (auto u : graph[v]) {
		print_recursively(graph, u, words);
	}
}

int main() {
	ios_base::sync_with_stdio(false); // fast IO
	cin.tie(NULL);

	int n, u, v, last_index = 0;
	cin >> n;
	string s;
	vector<string> words;
	for (int i = 0; i < n; i++) {
		cin >> s;
		words.push_back(s);
	}

	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		u -= 1;
		v -= 1;
		graph[u].push_back(v);
		last_index = u;
	}

	print_recursively(graph, last_index, words);
	return 0;
}
