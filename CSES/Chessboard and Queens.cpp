#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
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

int ans = 0, n = 8;
int cols[10], diag1[20], diag2[20];

void backtrancking(int y, vvi& board) {
    if (y == n) {
        ans += 1;
        return;
    }
    FOR(i, n) {
        if (cols[i] || diag1[i+y] || diag2[i-y+n-1] || !~board[y][i]) continue;
        cols[i] = diag1[i+y] = diag2[i-y+n-1] = 1;
        backtrancking(y + 1, board);
        cols[i] = diag1[i+y] = diag2[i-y+n-1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    fill(cols, 0);
    fill(diag1, 0);
    fill(diag2, 0);
    string str;
    vvi board(8, vi(8, 0));
    ans = 0;
    FOR(i, n) {
        cin >> str;
        FOR(j, n) {
            board[i][j] = (str[j] == '*' ? -1 : 0);
        }
    }
    backtrancking(0, board);
    cout << ans << bl;
    return 0;
}