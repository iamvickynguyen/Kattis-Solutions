#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main() {
  constexpr int MAX = 500005;

  string s;
  cin >> s;

  int counter[9][9];
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      counter[i][j] = 0;
    }
  }

  for (int i = 1; i < s.length(); ++i) {
    ++counter[s[i - 1] - '1'][s[i] - '1'];
  }

  vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int ans = MAX;
  do {
    int pos[9];
    for (int i = 0; i < 9; ++i)
      pos[nums[i]] = i;

    int count = abs(pos[nums[0]] - pos[s[0] - '1']) + 1;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        count += counter[i][j] * (abs(pos[i] - pos[j]) + 1);
      }
    }
    ans = min(ans, count);
  } while (next_permutation(nums.begin(), nums.end()));

  cout << ans;
  return 0;
}
