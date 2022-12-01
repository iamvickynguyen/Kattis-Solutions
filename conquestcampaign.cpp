#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
  int r, c, n, y, x;
  cin >> r >> c >> n;

  vector<vector<int>> countries(r, vector<int>(c, -1));
  queue<tuple<int, int, int>> q;
  for (int i = 0; i < n; ++i) {
    cin >> y >> x;
    --y;
    --x;
    countries[y][x] = 1;
    q.push({y, x, 1});
  }

  int ans = 1;
  while (!q.empty()) {
    auto [row, col, day] = q.front();
    q.pop();

    pair<int, int> neighbors[] = {
        {row - 1, col}, {row + 1, col}, {row, col - 1}, {row, col + 1}};
    for (auto &[i, j] : neighbors) {
      if (i >= 0 && i < r && j >= 0 && j < c && countries[i][j] == -1) {
        countries[i][j] = day + 1;
        ans = max(ans, day + 1);
        q.push({i, j, day + 1});
      }
    }
  }

  cout << ans;
  return 0;
}
