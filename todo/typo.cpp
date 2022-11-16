#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
using ll = long long int;

constexpr int P = 17;
constexpr int M = 52147;

unordered_set<ll> hashes;
vector<ll> power;

ll compute_hash(const string &s) {
	ll result = 0LL;
	for (int i = 0; i < s.length(); ++i) {
		result = (result + 1LL * (s[i] - 'a' + 1) * power[i] % M) % M;
	}
	return result;
}

// rolling hash with the head part and the tail part
// ignore the removed character, then combine
bool is_typo(const string &s) {
	ll head = 0LL, tail = 0LL;
	
	// compute tail hash
	for (int i = 1; i < s.length(); ++i) {
		tail = (tail + 1LL * (s[i] - 'a' + 1) * power[i - 1] % M) % M;
	}

	ll h = (head + tail) % M;
	cout << "roll: " << h << '\n';
	if (hashes.find(h) != hashes.end())
		return true;

	// rolling hash with removing a character
	for (int i = 0; i < (s.length() - 1); ++i) {
		head = (head + 1LL * (s[i] - 'a' + 1) * power[i] % M) % M;
		tail -= 1LL * (s[i + 1] - 'a' + 1) * power[i];
		h = (head + tail) % M;
	cout << "roll: " << h << '\n';
		if (hashes.find(h) != hashes.end())
			return true;
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	
	constexpr int maxn = 50;
	power.reserve(maxn);
	power[0] = P;
	for (int i = 1; i < maxn; ++i) {
		power[i] = power[i - 1] * P % M;
	}

	vector<string> words;
	words.reserve(n);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		words.push_back(s);
		cout << "HERE: " << s << '\n';
//		hashes.insert(compute_hash(s));

		ll h = compute_hash(s);
		cout << "HASH: " << h << '\n';
		hashes.insert(h);
	}

	for (auto w: words) {
		cout << "CHECKING: " << w << '\n';
		if (is_typo(w)) cout << w << '\n';
	}

	return 0;
}
