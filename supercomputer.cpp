#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Reference: https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/FenwickTree.java
class FenwickTree {
	private:
		vll ft;

		/**
		 * To get next
		 * 1) 2's complement of get minus of index
		 * 2) AND this with index
		 * 3) Add it to index
		 */
		int getNext(int idx) {
			return idx + (idx & -idx);
		}
		
		/**
		 * To get parent
		 * 1) 2's complement to get minus of index
		 * 2) AND this with index
		 * 3) Subtract that from index
		 */
		int getParent(int idx) {
			return idx - (idx & -idx);
		}

	public:
		FenwickTree(int n) { ft.assign(n + 1, 0); }
		FenwickTree(const vll &input) { create(input); }

		void update(ll val, int idx) {
			idx++;
			while (idx < ft.size()) {
				ft[idx] += val;
				idx = getNext(idx);
			}
		}

		void create(const vll &input) {
			int n = input.size();
			ft.assign(n + 1, 0);
			for (int i = 0; i < n; i++) {
				update(input[i], i);
			}
		}
		
		// get sum from [0, idx-1]
		ll getSum(int idx) {
			ll sum = 0;
			while (idx > 0) {
				sum += ft[idx];
				idx = getParent(idx);
			}
			return sum;
		}
};	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, i, l, r;
	cin >> n >> k;
	char c;
	vi bits(n, 0);
	FenwickTree ft(n);
	while (k--) {
		cin >> c;
		if (c == 'F') {
			cin >> i;
			i--;
			int val = (bits[i] == 0) ? 1 : -1;
			bits[i] ^= 1;
			ft.update(val, i);
		} else {
			cin >> l >> r;
			ll ans = ft.getSum(r) - ft.getSum(l - 1);
			cout << ans << '\n';
		}
	}
	
	return 0;
}
