#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <queue>
using namespace std;

/* The idea is to use topological sort
 * Keep trimming the nodes that have 0 in-degree with BFS
 */

int main() {
	int n;
	string line, token, package;
	cin >> n;
	while (n != 0) {
		cin.ignore();
		
		// construct the graph and in-degree map
		unordered_map<string, vector<string>> graph;
		unordered_map<string, int> degrees;
		for (int i = 0; i < n; ++i) {	
			getline(cin, line);
			stringstream ss(line);
			getline(ss, package, ' ');
			degrees[package] = 0;

			while (getline(ss, token, ' ')) {
				graph[token].push_back(package);
				++degrees[package];
			}
		}

		// put all the 0 in-degree nodes into the queue
		priority_queue<string, vector<string>, greater<string>> q;
		unordered_set<string> seen;
		for (auto &[node, deg]: degrees) {
			if (deg == 0) {
				q.push(node);
				seen.insert(node);
			}
		}

		// BFS
		vector<string> ans;
		bool loop = false;
		while (!q.empty()) {
			string u = q.top();
			q.pop();

			ans.push_back(u);

			for (auto &v: graph[u]) {
				if (seen.find(v) != seen.end()) {
					loop = true;
					break;
				}

				--degrees[v];
				if (degrees[v] == 0) {
					q.push(v);
					seen.insert(v);
				}
			}

			if (loop) break;
		}

		if (loop || ans.size() != n) {
			cout << "cannot be ordered\n";
		} else {
			for (auto &s: ans) cout << s << '\n';
		}

		cout << '\n';
		cin >> n;
	}

	return 0;
}
