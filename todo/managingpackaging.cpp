#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include<queue>
#include <algorithm>
using namespace std;

/* The idea is to use topological sort
 * Remove the nodes that have 0 in-degree
 */

using um = unordered_map<string, vector<string>>;

int main() {
	int n;
	string line, token, package;
	cin >> n;
	while (n != 0) {
		um graph;
		cin.ignore();
		
		// construct the graph with in-degree
		while (n--) {	
			getline(cin, line);
			stringstream ss(line);
			getline(ss, package, ' ');
			graph[package] = {};
			
			while (getline(ss, token, ' ')) {
				graph[package].push_back(token);
			}
		}

		// construct a degree map
		// at the same time, put all the nodes that have 0 in-degree into a queue
		// then do BFS to find the ordering
		unordered_map<string, int> degrees;
		queue<string> q;
		unordered_set<string> seen;
		for (auto &[u, v]: graph) {
			degrees[u] = v.size();
			if (v.size() == 0) {
				q.push(u);
				seen.insert(u);	
			}
		}

		// topological sort (basically, BFS)
		vector<string> ans;
		bool loop = false;

		while (!q.empty()) {
			vector<string> tmp;
			queue<string> q2;
			while (!q.empty()) {
				string u = q.front();
				q.pop();

				tmp.push_back(u);
				for (auto &v: graph[u]) {
					if (seen.find(v) != seen.end()) {
						loop = true;
						goto output;
					}

					--degrees[v];
					if (degrees[v] == 0) {
						q2.push(v);
						seen.insert(v);
					}
				}
			}

			sort(tmp.begin(), tmp.end());
			ans.insert(ans.end(), tmp.begin(), tmp.end());
			q = q2;
		}

output:
		if (loop) {
			cout << "cannot be ordered\n";
		} else {
			for (auto &s: ans) cout << s << '\n';
		}
	}

	return 0;
}
