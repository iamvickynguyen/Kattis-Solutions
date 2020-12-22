#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <cmath>
using namespace std;

struct country {
	bool left = false;
	int partners_count = 0;
	int partners_left = 0;
	vector<int> partners;
};

int main() {
	int c, p, x, l, a, b;
	cin >> c >> p >> x >> l;
	vector<country> countries;
	for (int i = 0; i < c + 1; i++) {
		country c;
		countries.push_back(c);
	}

	for (int i = 0; i < p; i++) {
		cin >> a >> b;
		countries[a].partners.push_back(b);
		countries[a].partners_count++;

		countries[b].partners.push_back(a);
		countries[b].partners_count++;
	}

	queue<int> q;
	q.push(l);
	countries[l].left = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (auto c : countries[v].partners) {
			if (!countries[c].left) {
				countries[c].partners_left++;
				if (ceil(countries[c].partners_count + 0.0) / 2 <= countries[c].partners_left) {
					q.push(c);
					countries[c].left = true;
				}	
			}
		}
	}

	if (countries[x].left)
		cout << "leave";
	else
		cout << "stay";

	return 0;
}