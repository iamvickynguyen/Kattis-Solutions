#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
typedef unordered_map<string, vector<string>> um;
um graph;
um graph_t;
unordered_set<string> visited;
stack<string> st;
vector<string> scc;

void dfs(string start, int pass) {
	visited.insert(start);
	vector<string> neighbours = (pass == 1) ? graph[start] : graph_t[start];
	for (auto n : neighbours) {
		if (visited.find(n) == visited.end()) {
			dfs(n, pass);
		}
	}

	if (pass == 1)
		st.push(start);
	else
		scc.push_back(start);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();
	string line;
	um lines;
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		stringstream ss(line);
		string name;
		string tok;
		getline(ss, name, ' ');
		while (getline(ss, tok, ' ')) {
			lines[name].push_back(tok);
		}
	}
	
	// create 2 maps, languages people can speak and languages people can understand
	um speak;
	um understand;
	for (auto item : lines) {
		vector<string> langs = item.second;
		speak[langs[0]].push_back(item.first);
		for (int i = 1; i < langs.size(); i++) {
			understand[langs[i]].push_back(item.first);
		}
	}

	// build directed graph
	for (auto item : speak) {
		for (auto person : item.second) {

			// connect people that can speak the same language
			graph[person] = item.second;

			// create an edge from a person can speak the language to people can understand the language
			graph[person].insert(graph[person].end(), understand[item.first].begin(), understand[item.first].end());
		}

	}

	// build transpose graph
	for (auto item : graph) {
		for (auto v : item.second) {
			graph_t[v].push_back(item.first);
		}
	}

	// find SCCs
	for (auto item : graph) {
		if (visited.find(item.first) == visited.end())
			dfs(item.first, 1);
	}

	int maxsize = 0;
	visited.clear();
	while (!st.empty()) {
		string u = st.top();
		st.pop();
		if (visited.find(u) == visited.end()) {
			scc.clear();
			dfs(u, 2);
			maxsize = max(maxsize, static_cast<int>(scc.size()));
		}
	}

	cout << (n - maxsize);
	return 0;
}