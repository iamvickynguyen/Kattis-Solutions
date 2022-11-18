#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long int;

constexpr int P = 73;
constexpr ll M1 = 253707997;
constexpr ll M2 = 111111571;

set<pair<ll, ll>> hashes;
vector<ll> power1;
vector<ll> power2;

ll compute_string_hash(const string &s, const ll M, vector<ll> &power) {
	ll result = 0LL;
	for (int i = 0; i < s.length(); ++i) {
//		result = (result + 1LL * (s[i] - 'a' + 1) * power[i] % M) % M;
		result += (power[i] * (s[i] - 'a' + 1)) % M;
		result %= M;

//		result *= P;
//		result %= M;
//		result += (s[i] - 'a' + 1);
//		result %= M;
	}
	return result;
}

// rolling hash with the head part and the tail part
// ignore the removed character, then combine
bool is_typo(const string &s) {
	ll head = 0LL, tail = 0LL;
	ll head2 = 0LL, tail2 = 0LL;
	
	// compute tail hash
	for (int i = 1; i < s.length(); ++i) {
//		tail = (tail + 1LL * (s[i] - 'a' + 1) * power[i - 1] % M) % M;
		tail += (power1[i - 1] * (s[i] - 'a' + 1)) % M1;
		tail %= M1;
		
		tail2 += (power2[i - 1] * (s[i] - 'a' + 1)) % M2;
		tail2 %= M2;
	}

	ll h1 = (head + tail) % M1;
	ll h2 = (head2 + tail2) % M2;
	if (hashes.find({h1, h2}) != hashes.end())
		return true;

	// rolling hash with removing a character
	for (int i = 0; i < (s.length() - 1); ++i) {
//		head = (head + 1LL * (s[i] - 'a' + 1) * power[i] % M) % M;
//		tail -= 1LL * (s[i + 1] - 'a' + 1) * power[i];

		head += (power1[i] * (s[i] - 'a' + 1)) % M1;
		head %= M1;
		tail -= (power1[i] * (s[i + 1] - 'a' + 1)) % M1;
		tail %= M1;

		head2 += (power2[i] * (s[i] - 'a' + 1)) % M2;
		head2 %= M2;
		tail2 -= (power2[i] * (s[i + 1] - 'a' + 1)) % M2;
		tail2 %= M2;
		
		h1 = (head + tail) % M1;
		h2 = (head2 + tail2) % M2;

		if (hashes.find({h1, h2}) != hashes.end())
			return true;
	}

	return false;
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
//		cout << "CHECKING: " << w << '\n';
		if (is_typo(w)) {
			flag = true;
			cout << w << '\n';	
		}
	}

	if (!flag) cout << "NO TYPOS\n";
	return 0;
}
