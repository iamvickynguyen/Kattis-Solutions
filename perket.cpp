#include <stdio.h> 
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/print-subsets-given-size-set/
int result = 1000000000;
void combinationUtil(vector<pair<int, int>> ingredients, int n, int r, int index, vector<pair<int, int>> data, int i)
{
	if (index == r) {
		int s = 1;
		int b = 0;
		for (int j = 0; j < r; j++) {
			s *= data[j].first;
			b += data[j].second;
			result = min(abs(s - b), result);
		}
		return;
	}
	if (i >= n)
		return;

	data[index] = ingredients[i];
	combinationUtil(ingredients, n, r, index + 1, data, i + 1);
	combinationUtil(ingredients, n, r, index, data, i + 1);
}

void findOptimal(vector<pair<int, int>> ingredients, int n, int r)
{
	vector<pair<int, int>> data = ingredients;
	combinationUtil(ingredients, n, r, 0, data, 0);
}

int main()
{
	int n, s, b;
	cin >> n;
	vector<pair<int, int>> ingredients;
	for (int i = 0; i < n; i++) {
		cin >> s >> b;
		ingredients.push_back(make_pair(s, b));
	}

	for (int element = 1; element <= n; element++) {
		findOptimal(ingredients, n, element);
	}
	cout << result;

	return 0;
}