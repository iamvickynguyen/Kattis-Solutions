#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set> 
#include <stack>
using namespace std;

string find_the_longest_path(vector<stack<string>> &result) {
	if (result.size() == 0)
		return "no route found";
	stack<string> path = result[0];

	// push items from the stack to vector, then iterate backwards
	vector<string> stations;
	while (!path.empty()) {
		string p = path.top();
		stations.push_back(p);
		path.pop();
	}

	string res;
	for (int i = stations.size() - 1; i > 0; i--) {
		res += stations[i] + ' ';
	}
	res += stations[0];
	return res;
}

void dfs(string s, string t, unordered_map<string, unordered_set<string>> &graph, unordered_set<string> &visited, stack<string> &path, vector<stack<string>> &result) {
	visited.insert(s);
	if (s == t) {
		result.push_back(path);
	}

	for (auto u : graph[s]) {
		if (visited.find(u) == visited.end()) {
			path.push(u);
			dfs(u, t, graph, visited, path, result);
			path.pop();
		}
	}
	visited.erase(s);
}

string find_all_paths(string s, string t, unordered_map<string, unordered_set<string>> &graph) {
	unordered_set<string> visited;
	stack<string> path;
	path.push(s);
	vector<stack<string>> result;
	dfs(s, t, graph, visited, path, result);
	return find_the_longest_path(result);
}

unordered_set<string> convert_list_to_set(vector<string> line) {
	unordered_set<string> s;
	for (int j = 1; j < line.size(); j++) {
		s.insert(line[j]);
	}
	return s;
}

void add_nodes(unordered_map<string, unordered_set<string>> &graph, vector<string> line) {
	unordered_set<string> converted = convert_list_to_set(line);
	if (graph.find(line[0]) == graph.end()) {
		graph[line[0]] = converted;
	}
	else {
		graph[line[0]].insert(converted.begin(), converted.end());
	}

	for (auto u : converted) {
		if (graph.find(u) == graph.end()) {
			unordered_set<string> s{ line[0] };
			graph[u] = s;
		}
		else {
			graph[u].insert(line[0]);
		}
	}
}

void clean_graph(unordered_map<string, unordered_set<string>> &graph) {
	for (auto& it : graph) {
		string v = it.first;
		if (graph[v].find(v) != graph[v].end()) {
			graph[v].erase(v);
		}
	}
}

int main() {
	unordered_map<string, unordered_set<string>> graph;
	int n;
	cin >> n;
	string line;
	getline(cin, line);; //flush
	for (int i = 0; i < n; i++) {
		vector<string> v;
		getline(cin, line);
		stringstream ss(line);
		string tok;
		while (getline(ss, tok, ' ')) {
			v.push_back(tok);
		}

		add_nodes(graph, v);
	}

	// remove v from graph[v]
	clean_graph(graph);

	string s, t;
	cin >> s >> t;
	string result = find_all_paths(s, t, graph);
	cout << result;
}