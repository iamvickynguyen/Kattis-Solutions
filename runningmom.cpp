#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;
typedef unordered_set<string> us;
typedef unordered_map<string, vector<string>> um;

bool dfs(string v, um graph, us &visiting, us &trapped, us &safe) {
	visiting.insert(v);
	for (auto u : graph[v]) {
		if (visiting.find(u) != visiting.end() || safe.find(u) != safe.end() || dfs(u, graph, visiting, trapped, safe))
			return true;
	}

	trapped.insert(v);
	visiting.erase(v);
	return false;
}

bool detect_cycle(us &safe, us &trapped, um graph, string v) {
	if (safe.find(v) != safe.end()) return true;
	if (trapped.find(v) != trapped.end()) return false;
	us visiting;
	bool result = dfs(v, graph, visiting, trapped, safe);
	for (auto u : visiting)
		safe.insert(u);
	return result;
}

int main() {
	int n;
	cin >> n;
	string s, t;
	um graph;
	while (n--) {
		cin >> s >> t;
		graph[s].push_back(t);
	}

	us safe;
	us trapped;
	while (cin >> s) {
		if (detect_cycle(safe, trapped, graph, s))
			cout << s << " safe" << endl;
		else
			cout << s << " trapped" << endl;
	}
		
	return 0;
}