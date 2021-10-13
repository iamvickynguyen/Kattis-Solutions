#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MAXN = 40000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    while (n) {
        vector<bool> primes(MAXN, true);
        primes[1] = false;

        int p = 2;
        while (p * p <= n) {
            if (primes[p]) {
                for (int i = p * p; i <= n; i += p)
                    primes[i] = false;
            }
            p += 1;
        }

        for (int i = 2*n; i < MAXN; i++) {
            if (primes[i]) {
                cout << i;
                break;
            }
        }

        if (!primes[n]) cout << "(" << n << " is not prime)";
        cout << '\n';

        cin >> n;
    }

	return 0;
}
