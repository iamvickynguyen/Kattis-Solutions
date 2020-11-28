#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;

void in(vector<int>& d1, vector<int>& d2, int n) {
	int mid = n / 2;
	int i = 0, j = mid, pos = 0;
	for (int k = 0; k < mid; k++) {
		if (j < n)
			d2[pos++] = d1[j++];
		if (i < mid)
			d2[pos++] = d1[i++];
	}
}

void out(vector<int>& d1, vector<int>& d2, int n) {
	int mid = n % 2 == 0 ? n / 2 : n / 2 + 1;
	int i = 0, j = mid, pos = 0;
	for (int k = 0; k < mid; k++) {
		if (i < mid)
			d2[pos++] = d1[i++];
		if (j < n)
			d2[pos++] = d1[j++];
	}
}

bool check(vector<int> d, int n) {
	for (int i = 0; i < n; i++) {
		if (d[i] != i)
			return false;
	}
	return true;
}

int main() {
	int n;
	char s[4];
	scanf("%d %s", &n, s);

	if (n == 1)
		printf("1");
	else if (n == 2) {
		if (strcmp(s, "out") == 0)
			printf("1");
		else
			printf("2");
	}
	else {
		vector<int> d1;
		vector<int> d2;
		for (int i = 0; i < n; i++) {
			d1.push_back(i);
			d2.push_back(i);
		}

		int count = 1;
		if (strcmp(s, "out") == 0) {
			out(d1, d2, n);
			while (true) {
				if (count % 2 == 1) {
					if (check(d2, n))
						break;
					out(d2, d1, n);
					count++;
				}
				else {
					if (check(d1, n))
						break;
					out(d1, d2, n);
					count++;
				}
			}
		}
		else {
			in(d1, d2, n);
			while (true) {
				if (count % 2 == 1) {
					if (check(d2, n))
						break;
					in(d2, d1, n);
					count++;
				}
				else {
					if (check(d1, n))
						break;
					in(d1, d2, n);
					count++;
				}
			}	
		}

		printf("%d", count);
	}

	return 0;
}