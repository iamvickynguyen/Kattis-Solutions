#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// https://github.com/mission-peace/interview/blob/master/src/com/interview/array/LongestIncreasingSubSequenceOlogNMethod.java

int binary_search(vector<int> &a, vector<int> &T, int end, int s) {
	int start = 0;
	int middle;
	int len = end;
	while (start <= end) {
		middle = start + (end - start) / 2;
		if (middle < len && a[T[middle]] < s && s <= a[T[middle + 1]])
			return middle + 1;
		else if (a[T[middle]] < s)
			start = middle + 1;
		else
			end = middle - 1;
	}
	return -1;
}

void LIS(vector<int> &a, int n) {
	vector<int> T(n);
	vector<int> R(n, -1);
	T[0] = 0;
	int len = 0;
	for (int i = 1; i < n; i++) {
		if (a[T[0]] > a[i])
			T[0] = i;
		else if (a[T[len]] < a[i]) {
			len++;
			T[len] = i;
			R[T[len]] = T[len - 1];
		}
		else {
			int index = binary_search(a, T, len, a[i]);
			if (index > -1) {
				T[index] = i;
				R[T[index]] = T[index - 1];
			}
		}
	}

	// print subsequence
	cout << len + 1 << '\n';
	vector<int> result;
	int index = T[len];
	while (index != -1) {
		result.push_back(index);
		index = R[index];
	}
	for (int i = len; i > 0; i--) {
		cout << result[i] << ' ';
	}
	cout << result[0] << endl;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> a;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			a.push_back(x);
		}
		LIS(a, n);
	}
	return 0;
}