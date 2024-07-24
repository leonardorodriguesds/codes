#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif
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
#define debugarr(arr)   if (DEBUG) { for(auto a: arr) { cout << a << " "; } cout << bl; }
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

int n, m;
unordered_map<char, ii> directions = {
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'U', {-1, 0}},
    {'D', {1, 0}}
};

bool check(int i, int j, vs& grid, vvi& visited) {
    return (i >= 0 && i < n && j >= 0 && j < m && !~visited[i][j]) && (grid[i][j] == '.' || grid[i][j] == 'B');
}

ii bfs(int i, int j, vs& grid, vvi& visited, vector<vector<pair<ii, char>>>& parent) {
    visited[i][j] = 1;
    queue<ii> q;
    parent[i][j] = {{-1, -1}, 'A'};
    q.emplace(i, j);

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (auto dirs : directions) {
            char d = dirs.first;
            ii dir = dirs.second;
            int xi = x + dir.first, yj = y + dir.second;

            if (check(xi, yj, grid, visited)) {
                parent[xi][yj] = {{x, y}, d};

                if (grid[xi][yj] == 'B') {
                    return {xi, yj};
                }

                q.emplace(xi, yj);
                visited[xi][yj] = 1;
            }
        }
    }

    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cin >> n >> m;
    vs grid(n);
    FOR(i, n) cin >> grid[i];
    ii ans = {-1, -1};
    vvi visited(n, vi(m, -1));
    vector<vector<pair<ii, char>>> parent(n, vector<pair<ii, char>>(m));

    FOR(i, n) {
        FOR(j, m) {
            if (grid[i][j] == 'A') {
                ans = bfs(i, j, grid, visited, parent);
            }
        }
    }

    if (ans.first >= 0 && ans.second >= 0) {
        string path;
        int i = ans.first, j = ans.second;
        int total = 0;

        pair<ii, char> dir = parent[i][j];
        while (dir.second != 'A') {
            path.push_back(dir.second);
            dir = parent[dir.first.first][dir.first.second];
            total++;
        }

        cout << "YES" << bl << total << bl;
        reverse(all(path));
        cout << path << bl;
    } else cout << "NO" << bl;

    return 0;
}