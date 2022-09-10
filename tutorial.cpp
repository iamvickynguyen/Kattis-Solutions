#include <math.h>
#include <iostream>
using namespace std;

bool check_factorial(const int n, const int m) {
  if (n > m) return false;
  long long int val = 1;
  for (long long int i = 2LL; i <= n * 1LL; ++i) {
    val *= i;
    if (val > m) return false;
  }
  return true;
}

bool check_exp(const int n, const int m, const int k) {
  long long int val = 1LL;
  for (int i = 0; i < k; ++i) {
    val *= 1LL * n;
    if (val > m) return false;
  }
  return true;
}

bool check_6(const int n, const int m) {
  double x = (double)n;
  double k = log2(x) * x;
  return k <= (double)m;
}

int main() {
  int m, n, t;
  cin >> m >> n >> t;
  bool ans;

  if (t == 1)
    ans = check_factorial(n, m);
  else if (t == 2)
    ans = check_exp(2, m, n);
  else if (t == 3)
    ans = check_exp(n, m, 4);
  else if (t == 4)
    ans = check_exp(n, m, 3);
  else if (t == 5)
    ans = check_exp(n, m, 2);
  else if (t == 6)
    ans = check_6(n, m);
  else
    ans = (n <= m);

  if (ans) cout << "AC";
  else cout << "TLE";

  return 0;
}
