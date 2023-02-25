#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int months = (n - 2018) * 12 + 8;
  if (months % 26 < 12)
    cout << "yes";
  else
    cout << "no";
  return 0;
}
