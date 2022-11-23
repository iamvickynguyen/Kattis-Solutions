#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long int;

constexpr int P = 31;
constexpr ll M1 = 253707997;
constexpr ll M2 = 111111571;

set<pair<ll, ll>> hashes;
vector<ll> power1;
vector<ll> power2;

ll compute_string_hash(const string &s, const ll M, vector<ll> &power) {
	ll result = 0LL;
	for (int i = 0; i < s.length(); ++i) {
		result += ((power[i] * (s[i] - 'a' + 1)) % M);
		result %= M;
	}
	return result;
}

// rolling hash with the head part and the tail part
// ignore the removed character, then combine
vector<ll> rolling_hash(const string &s, const ll M, const vector<ll> &power) {
	vector<ll> hashes;
	hashes.reserve(s.length());

	ll head = 0LL, tail = 0LL;
	
	// compute tail hash
	for (int i = 1; i < s.length(); ++i) {
		tail += ((power[i - 1] * (s[i] - 'a' + 1)) % M);
		tail %= M;
	}

	ll h = (head + tail) % M;
	cout << h << '\n';
	hashes.push_back(h);

	// rolling hash with removing a character
	for (int i = 0; i < (s.length() - 1); ++i) {
		head += ((power[i] * (s[i] - 'a' + 1)) % M);
		head %= M;
		tail -= ((power[i] * (s[i + 1] - 'a' + 1)) % M);
		tail %= M;

		h = (head + tail) % M;
		cout << h << '\n';
		hashes.push_back(h);
	}
	
	return hashes;
}


void compute_power(vector<ll> &power, const int maxlength, const ll M) {
	power.reserve(maxlength);
	power[0] = P;
	for (int i = 1; i < maxlength; ++i) power[i] = (power[i - 1] * P) % M;
}

int main() {
	int n;
	cin >> n;

	int maxlength = 0;
	vector<string> words;
	words.reserve(n);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		words.push_back(s);
		maxlength = max(maxlength, (int)s.length());
	}
	
	// precompute power
	compute_power(power1, maxlength, M1);
	compute_power(power2, maxlength, M2);

	// string hash
	for (auto &word: words) {
		ll h1 = compute_string_hash(word, M1, power1);
		ll h2 = compute_string_hash(word, M2, power2);
//		cout << word << ": " << h1 << ", " << h2 << '\n';
		hashes.insert({h1, h2});
	}

	bool flag = false;
	for (auto w: words) {
		vector<ll> hashes1 = rolling_hash(w, M1, power1);
		vector<ll> hashes2 = rolling_hash(w, M2, power2);
		for (int i = 0; i < hashes1.size(); ++i) {
			if (hashes.find({hashes1[i], hashes2[i]}) != hashes.end()) {
				flag = true;
//				cout << w << '\n';
				break;
			}
		}
	}

	if (!flag) cout << "NO TYPOS\n";
	return 0;
}
