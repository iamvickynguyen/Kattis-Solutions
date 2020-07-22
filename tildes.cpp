#include <stdio.h>
#include <vector>
using namespace std;

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
		scanf(" %c", &x);
		if (x == 't') {
			scanf("%d %d", &a, &b);
			union_set(a - 1, b - 1);
		}		
		else {
			scanf("%d", &a);
			int root = find(a - 1);
			printf("%d\n", Size[root]);
		}
	}

	return 0;
}