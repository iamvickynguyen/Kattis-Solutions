#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef unordered_set<int> usi;
typedef unordered_map<int, vi> ivi;
typedef unordered_map<int, int> ii;
#define all(x) (x).begin(), (x).end()
#define pb push_back
// #define TIME

const int inf = 12;
vector<string> board(5);
vector<vector<char>> fen = {
    {'1', '1', '1', '1', '1'},
    {'0', '1', '1', '1', '1'},
    {'0', '0', ' ', '1', '1'},
    {'0', '0', '0', '0', '1'},
    {'0', '0', '0', '0', '0'}
};

bool check() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != fen[i][j])
                return false;
        }
    }
    return true;
}

int solve(int cnt, int row, int col) {
    if (cnt == 10) {
        if (check()) return cnt;
        return inf;
    }

    if (check()) return cnt;

    vector<pii> moves = {{row - 2, col - 1}, {row - 2, col + 1}, {row - 1, col + 2}, {row + 1, col + 2}, {row + 2, col + 1},
                        {row + 2, col - 1}, {row + 1, col - 2}, {row - 1, col - 2}};
    int best = inf;
    for (auto &u: moves) {
        int i = u.first, j = u.second;
        if (i >= 0 && i < 5 && j >= 0 && j < 5) {
            swap(board[i][j], board[row][col]);
            int steps = solve(cnt + 1, i, j);
            best = min(best, steps);
            swap(board[i][j], board[row][col]);
        }
    }
    return best;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        for (auto &s: board) {
            getline(cin, s);
        }

        // find empty cell
        int i, j;
        bool ok = false;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (board[i][j] == ' ') {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        int ans = solve(0, i, j);
        if (ans > 10) cout << "Unsolvable in less than 11 move(s).\n";
        else cout << "Solvable in " << ans << " move(s).\n";
    }

	#ifdef TIME
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
    #endif

    return 0;
}