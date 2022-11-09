#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;
using ll = long long int;

vector<pair<string, ll>> dictionary;
vector<ll> cache;
constexpr ll MOD = 1000000007;

bool is_match(const string &text, const string &pattern, const int start) {
	if (start + pattern.length() > text.length())
		return false;

	for (int i = 0; i < pattern.length(); ++i) {
		if (text[start + i] != pattern[i])
			return false;
	}

	return true;
}

ll explore(int i, const string &word) {
	if (i == word.length()) return 1LL;
	if (cache[i] != -1LL) return cache[i];
	
	pair<string, int> tmp = {string(1, word[i]), 0};
	int start = lower_bound(dictionary.begin(), dictionary.end(), tmp,
			[](const pair<string, int>&a, const pair<string, int>&b) { return a.first < b.first; } ) - dictionary.begin();
	
	ll ans = 0LL;
	for (int j = start; j < dictionary.size(); ++j) {
		if (dictionary[j].first[0] == word[i]) {
			if (is_match(word, dictionary[j].first, i)) {
				ans = (ans + (dictionary[j].second * explore(i + dictionary[j].first.length(), word)) % MOD) % MOD;
			}
		} else {
			break;
		}
	}

	cache[i] = ans;
	return ans;	
}

int main() {
	int n;
	ll val;
	string word, s;
	cin >> n >> word;

	dictionary.reserve(n);
	cache.assign(word.length(), -1LL);

	for (int i = 0; i < n; ++i) {
		cin >> s >> val;
		dictionary.push_back({s, val});
	}

	sort(dictionary.begin(), dictionary.end());
	cout << explore(0, word);
	return 0;
}
