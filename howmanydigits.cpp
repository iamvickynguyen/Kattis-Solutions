#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
    unordered_map<int, int> um;
    um[0] = 1;
    um[1] = 1;
    double result = 0.0;
    for (int i = 2; i < 1000001; i++) {
        result += log10(i);
        um[i] = ceil(result);
    }

    int n;
    while (cin >> n) {
        cout << um[n] << '\n';
    }

    return 0;
}