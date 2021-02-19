#include <iostream>
#include <utility>
#include <vector>
#include <set>
using namespace std;
const int INF = 200001;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    
    vector<int> dist(n, INF);
    dist[0] = 0;
    set<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
        pq.emplace(dist[i], i);

    while (!pq.empty()) {
        auto front = *pq.begin();
        int d = front.first, cur = front.second;
        pq.erase(pq.begin());

        for (auto item : graph[cur]) {
            int v = item.first, w = item.second;
            if (dist[cur] + w < dist[v]) {
                pq.erase(pq.find({dist[v], v}));
                dist[v] = dist[cur] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    cout << dist[n - 1];
    return 0;
}