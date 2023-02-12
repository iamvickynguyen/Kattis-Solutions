#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> counter;

  vector<int> top(n);
  for (auto &x : top) {
    cin >> x;
    counter[x] = 0;
  }

  vector<int> bottom(n);
  for (auto &x : bottom)
    cin >> x;

  vector<int> ans(n, 0);

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (counter[top[i]] < 0)
      --count;
    else
      ++count;
    ++counter[top[i]];

    if (counter[bottom[i]] > 0)
      --count;
    else
      ++count;
    --counter[bottom[i]];

    if (count == 0)
      ans[i] = 1;
  }

  for (int i = 0; i < n; ++i) {
    cout << bottom[i] << " ";
    if (ans[i] == 1 && i < n - 1) {
      cout << "# ";
    }
  }

  return 0;
}
