#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> get_list(ll x) {
	vector<ll> nums;
	nums.push_back(x);
	while (x != 1) {
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = x * 3 + 1LL;
		}
		nums.push_back(x);
	}

	nums.push_back(1LL);
	return nums;
}

int main() {
	ll a, b;
	cin >> a >> b;
	while (a != 0) {
		vector<ll> a_steps = get_list(a);
		vector<ll> b_steps = get_list(b);
		
		int pa = a_steps.size() - 1, pb = b_steps.size() - 1;
		while (pa >= 0 && pb >= 0 && a_steps[pa] == b_steps[pb]) {
			--pa;
			--pb;
		}

		cout << a << " needs " << (pa + 1) << " steps, "
			<< b << " needs " << (pb + 1) << " steps, they meet at " << a_steps[pa + 1] << '\n';
		cin >> a >> b;
	}

	return 0;
}
