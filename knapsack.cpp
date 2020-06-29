#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdio.h> 
using namespace std;

//https://www.geeksforgeeks.org/printing-items-01-knapsack/#:~:text=k%20groups%20incrementally-,Printing%20Items%20in%200%2F1%20Knapsack,associated%20with%20n%20items%20respectively.
vector<int> knapSack(int W, vector<int> wt, vector<int> val, int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	int res = K[n][W];

	w = W;
	vector<int> indexes;
	for (i = n; i > 0 && res > 0; i--) {
		if (res == K[i - 1][w])
			continue;
		else {
			indexes.push_back(i - 1);
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
	return indexes;
}

int main() {
	int c, n;
	while (cin >> c >> n) {
		vector<int> val;
		vector<int> wt;
		int v, w;
		for (int i = 0; i < n; i++) {
			cin >> v >> w;
			val.push_back(v);
			wt.push_back(w);
		}
		vector<int> indexes = knapSack(c, wt, val, n);
		cout << indexes.size() << '\n';
		for (int i : indexes)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}