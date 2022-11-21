#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll = long long int;

constexpr ll INF = 1e12;

struct Node {
	int id;
	ll weight;
	Node(int id, ll weight): id(id), weight(weight) {}
};

struct cmpNode {
	bool operator() (const Node &a, const Node &b) {
		return a.weight > b.weight;
	}
};

ll dijkstra(vector<unordered_map<int, ll>> &graph, const int N) {
	vector<ll> cost(N, INF);
	cost[N - 2] = 0LL;
	
	priority_queue<Node, vector<Node>, cmpNode> pq;
	pq.push(Node(N - 2, 0LL));
	
	while (!pq.empty()) {
		Node node = pq.top();
		pq.pop();
		
		if (node.weight > cost[node.id]) continue;

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
  int n, m, a, b, s, e;
  cin >> n >> m;

  // collect flight information
  vector<unordered_map<int, vector<int>>> flight_info(n); // index is source country, stores map of {destination country: list of flight id}
  vector<pair<int, int>> flight_id; // index is flight id, stores pair of {s, e}
  flight_id.reserve(m);
  
	// flight graph
	vector<unordered_map<int, ll>> graph(m + 2); // index is source flight id, stores map of {destination flight id: frustration}

  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> s >> e;
    --a;
    --b;
    flight_info[a][b].push_back(flight_id.size());
    flight_id.push_back({s, e});

		// connect last flights to destination node
		if (b == (n - 1)) {
			graph[flight_id.size() - 1][m + 1] = 0LL;
		}
  }

  queue<tuple<int, int, ll>> q;
	
	// connect source node to flights from the first airport
  for (auto &[airport, flights] : flight_info[0]) {
    for (auto &fid : flights) {
      auto &[start, end] = flight_id[fid];
      graph[m][fid] = 1LL * start * start;
      q.push({airport, fid, end});
    }
  }

	// connect flights between airports
  while (!q.empty()) {
    auto [from_airport, from_flight, arrival_time] = q.front();
    q.pop();

    for (auto &[to_airport, flights] : flight_info[from_airport]) {
      for (auto &fid : flights) {
        auto &[start, end] = flight_id[fid];
        if (start >= arrival_time) {
          ll wait = 1LL * (start - arrival_time);
          graph[from_flight][fid] = wait * wait;
          q.push({to_airport, fid, end});
        }
      }
    }
  }

	cout << dijkstra(graph, m + 2);
  return 0;
}
