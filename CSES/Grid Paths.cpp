#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA 256
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-9)
#define PI 3.141592653589793238462643383279502884
#define all(a) a.begin(), a.end()
#define fill(t,v) memset(t, v, sizeof(t))
#define sz(a) ((int)(a.size()))
#define LOG2(X) ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v) ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b) (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
#define bl "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

int n = 7, p = 0;
string path;
vector<vector<bool>> board = vector<vector<bool>>(7, vector<bool>(7, false));
ll ans = 0;
unordered_map<char, vi> directions = {
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};

bool valid(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < n && !board[i][j];
}

void backtracking(int i, int j, int s) {
    if (i == (n - 1) && j == 0 && s == p) {
        ans++;
    }
    if (s == p)
        return;    
    
    board[i][j] = true;
    char choice = path[s];
    if (choice == '?') {
        for (auto dirs : directions) {
            vi dir = dirs.second;
            int x = i + dir[0], y = j + dir[1];
            if (valid(x, y)) {
                backtracking(x, y, s + 1);
            }
        }
    } else {
        vi d = directions[choice];
        int x = i + d[0], y = j + d[1];
        if (valid(x, y)) {
            backtracking(x, y, s + 1);
        }
    }
    
    board[i][j] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> path;
    p = path.size();
    board[0][0] = true;
    backtracking(0, 0, 0);
    cout << ans << bl;
    return 0;
}
