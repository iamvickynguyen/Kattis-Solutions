#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;
  while (r != 0 && c != 0) {
    vector<string> grid(r);
    for (auto &s : grid) cin >> s;

    vector<string> transpose;
    transpose.reserve(c);
    for (int j = 0; j < c; ++j) {
      string s = "";
      for (int i = 0; i < r; ++i) {
        s.push_back(grid[i][j]);
      }
      transpose.push_back(s);
    }

    sort(transpose.begin(), transpose.end(),
         [](const string &a, const string &b) {
           for (int i = 0; i < a.length(); ++i) {
             if (tolower(a[i]) != tolower(b[i])) {
               return tolower(a[i]) < tolower(b[i]);
             }
           }
           return true;
         });

    for (int j = 0; j < r; ++j) {
      for (int i = 0; i < c; ++i) {
        cout << transpose[i][j];
      }
      cout << '\n';
    }

    cout << '\n';
    cin >> r >> c;
  }

  return 0;
}
