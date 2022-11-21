#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long int;

constexpr ll INF = 1e12;

struct Node {
	int next_airport;
	ll arrival_time;
	ll frustration;
	Node(int next_airport, ll arrival_time, ll frustration): next_airport(next_airport), arrival_time(arrival_time), frustration(frustration) {}
};

struct cmpNode {
	bool operator() (const Node &a, const Node &b) {
		return a.frustration > b.frustration;
	}
};

struct Flight {
	ll depart;
	ll arrive;
	int id;
	Flight(ll depart, ll arrive, int id): depart(depart), arrive(arrive), id(id) {}
};

ll dijkstra(vector<unordered_map<int, vector<pair<Flight>> &graph, const int N, const int M) {
	vector<ll> cost(M + 2, INF);
	cost[N - 2] = 0LL; // source node
	
	// push starting nodes
	priority_queue<Node, vector<Node>, cmpNode> pq;
	for (auto &[to_airport, flights]: graph[0]) {
		for (auto &f: flights) {
			ll waiting = f.depart * f.depart;
			pq.push(Node(to_airport, f.arrive, waiting));
			cost[f.id] = waiting;
		}
	}

	while (!pq.empty()) {
		Node node = pq.top();
		pq.pop();

		int next = node.next_airport;
		ll arrive = node.arrival_time;
		ll frust = node.frustration;
		
		// FIXME
		for (auto &[flight, frustration]: graph[node.id]) {
			ll new_cost = node.weight + frustration;
			if (new_cost < cost[flight]) {
				cost[flight] = new_cost;
				pq.push(Node(flight, new_cost));
			}
		}
	}

	return cost[N - 1];
}

int main() {
  int n, m, a, b;
	ll s, e;
  cin >> n >> m;

  // collect flight information
  vector<unordered_map<int, vector<Flight>> graph(n); // index is source country, stores map of {destination country: list of Flights} 

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> s >> e;
    --a;
    --b;
    graph[a][b].push_back(Flight(s, e, i));
  }

	// sort flight schedules so that we can use binary search to find the next possible flight
	for (int i = 0; i < n; ++i) {
		for (auto &[airport, schedules]: graph[i]) {
			sort(schedules.begin(), schedules.end(),
					[](const Flight &a, const Flight &b) { return a.depart < b.depart; });
		}
	}

	cout << dijkstra(graph, n, m);
  return 0;
}
