#include <stdio.h>
#include <vector>
using namespace std;

/* 
	Although it's just a normal union find algorithm, the optimization is a bit tricky.
	Using cout, cin will get TLE, but scanf, printf will pass.
*/


vector<int> Parent;
vector<int> Size;

int find(int e) {
	while (Parent[e] != e) {
		Parent[e] = Parent[Parent[e]];
		e = Parent[e];
	}
	return e;
}

void union_set(int e1, int e2) {
	int root1 = find(e1);
	int root2 = find(e2);
	if (root1 != root2) {
		if (Size[root1] < Size[root2]) {
			int tmp = root1;
			root1 = root2;
			root2 = tmp;
		}
		Parent[root2] = root1;
		Size[root1] += Size[root2];
	}
}

int main() {
	int n, q, a, b;
	char x;
	scanf("%d %d", &n, &q);

	for (int i = 0; i < n; i++) {
		Parent.push_back(i);
		Size.push_back(1);
	}

	for (int i = 0; i < q; i++) {
		scanf(" %c %d %d", &x, &a, &b);
		if (x == '=')
			union_set(a, b);
		else
			printf(find(a) != find(b) ? "no\n" : "yes\n");
	}

	return 0;
}