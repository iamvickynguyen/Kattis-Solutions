#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> moves;

void get_moves(vector<int> distance, int length, int position, int cur_dist, char direction, vector<char> move) {
	move.push_back(direction);

	if (cur_dist < 0 || position > length - 1) {
		return;
	}
	if (cur_dist < 0 || (position == length - 1 && cur_dist)) {
		return;
	}

	if (position == length - 1 && !cur_dist) {
		string s = "";
		for (auto c : move) {
			s += c;
		}
		moves.push_back(s);
		return;
	}

	get_moves(distance, length, position + 1, cur_dist + distance[position + 1], 'U', move);
	get_moves(distance, length, position + 1, cur_dist - distance[position + 1], 'D', move);
}

int get_max_height(vector<int> dist, string move) {
	int max_height = dist[0];
	int cur_height = dist[0];
	for (int i = 1; i < dist.size(); i++) {
		cur_height += move[i] == 'U' ? dist[i] : (-dist[i]);
		max_height = max(max_height, cur_height);
	}
	return max_height;
}

string get_opt_move(vector<int> dist) {
	if (!moves.size())
		return "IMPOSSIBLE";

	string result = moves[0];
	int lowest = 1000;
	for (auto s : moves) {
		int max_height = get_max_height(dist, s);
		if (lowest > max_height) {
			lowest = max_height;
			result = s;
		}
	}
	moves.clear();
	return result;
}

int main() {
	int n, m, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m) {
			vector<int> distance;
			for (int j = 0; j < m; j++) {
				scanf("%d", &x);
				distance.push_back(x);
			}
			vector<char> move;
			get_moves(distance, m, 0, distance[0], 'U', move);
			string opt = get_opt_move(distance);
			printf("%s\n", opt.c_str());
		}
	}

	return 0;
}