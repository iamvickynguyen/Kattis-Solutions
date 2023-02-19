#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int i = 1;
    for (i = 1; i < s.length(); ++i) {
      if (s[i] < s[i - 1])
        break;
    }

    while (i < s.length() && s[i - 1] >= s[i])
      ++i;

    for (int j = i; j < s.length(); ++j) {
      s[j] = s[j - 1];
    }

    cout << s << '\n';
  }

  return 0;
}
