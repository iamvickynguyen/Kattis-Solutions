#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
typedef pair<int, int> ii;

int main() {
    string row;
    vector<string> graph;
    vector<ii> knights;
	for (int i = 0; i < 5; i++) {
		cin >> row;
		for (int j = 0; j < 5; j++) {
			if (row[j] == 'k')
				knights.push_back(make_pair(j, i));
		}
		graph.push_back(row);
	}

    ii moves[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
    bool valid = true;

    if (knights.size() != 9) {
        valid = false;
        cout << "invalid";
    } else {
        for (auto k : knights) {
            for (auto m : moves) {
                int x = m.first + k.first, y = m.second + k.second;
                if (0 <= x && x < 5 && 0 <= y && y < 5) {
                    if (graph[y][x] == 'k') {
                        valid = false;
                        cout << "invalid";
                        break;
                    }
                }
            }

            if (!valid)
                break;
        }
    }

    if (valid)
        cout << "valid";
    return 0;
}