#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &x : v)
    cin >> x;

  bool ok = false;
  for (int i = 1; i < n; ++i) {
    if (v[i - 1].length() == v[i].length()) {
      if (v[i].length() == 1) {
        if (v[i][0] != '9') {
          v[i - 1][0] = '9';
          ok = true;
          break;
        } else if (v[i - 1][0] != '0') {
          v[i][0] = '0';
          ok = true;
          break;
        }
      } else {
        if (v[i][0] != '9') {
          v[i - 1][0] = '9';
          ok = true;
          break;
        } else if (v[i - 1][0] != '1') {
          v[i][0] = '1';
          ok = true;
          break;
        }
      }
    }
  }

  if (!ok)
    cout << "impossible";
  else {
    for (auto x : v)
      cout << x << " ";
  }

  return 0;
}
