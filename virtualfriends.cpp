#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue<int, vector<int>, greater<int>> minpq;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
#define all(x) (x).begin(), (x).end()
#define pb push_back

unordered_map<string, string> Parent;
unordered_map<string, int> Size;

string find(string &node) {
    if (Parent[node] != node) Parent[node] = find(Parent[node]);
    return Parent[node];
}

int merge (string &a, string &b) {
    string ra = find(a), rb = find(b);
    if (ra == rb) return Size[ra];
    if (Size[ra] < Size[rb]) ra.swap(rb);
    Parent[rb] = ra;
    Size[ra] += Size[rb];
    return Size[ra];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        Parent.clear();
        Size.clear();

        string a, b;
        while (n--) {
            cin >> a >> b;

            if (Parent.count(a) == 0) {
                Parent[a] = a;
                Size[a] = 1;
            }

            if (Parent.count(b) == 0) {
                Parent[b] = b;
                Size[b] = 1;
            }

            cout << merge(a, b) << '\n';
        }
    }

    return 0;
}
