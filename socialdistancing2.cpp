#include <iostream>
#include <vector>
using namespace std;

int main() {
  int s, n;
  cin >> s >> n;
  vector<int> seats(n);
  for (auto &x : seats)
    cin >> x;

  int ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    int count = ((seats[i + 1] - seats[i]) / 2) - 1;
    if (count > 0)
      ans += count;
  }

  int count = ((seats[0] + s - seats[n - 1]) / 2) - 1;
  if (count > 0)
    ans += count;

  cout << ans;
  return 0;
}
