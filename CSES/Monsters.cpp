#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define DEBUG false
#else
    #define DEBUG true
#endif
#define debugf if (DEBUG) printf
#define MAXN 1001
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
int monstersCount = 0;
vs grid;
vii monsters;

struct Move {
    ii pos;
    string moves;
    vii monsters_positions;
};
int visited[MAXN][MAXN];

bool is_safe(ii pos, vii monsters_position) {
    for(ii monster: monsters_position) {
        if (pos.first == monster.first && pos.second == monster.second)
            return false;
    }

    return true;
}

vii generate_monsters_positions(vii monsters) {
    vii new_monsters_positions;

    for(ii monster: monsters) {
        for (pair<char, ii> dir : directions) {
            ii d = {dir.second.first + monster.first, dir.second.second + monster.second};

            if (d.first < 0 || d.first >= n || d.second < 0 || d.second >= m || grid[d.first][d.second] == '#')
                new_monsters_positions.pb(monster);
            else
                new_monsters_positions.pb(d);
        }
    }
    return new_monsters_positions;
}

void bfs(int i, int j) {
    queue<Move> queue;
    visited[i][j] = 1;
    queue.push({{i, j}, "", monsters});

    while (!queue.empty()) {
        Move move = queue.front();
        queue.pop();
        ii pos = move.pos;
        vii monsters_pos = move.monsters_positions;

        if (pos.first == n - 1 || pos.first == 0 || pos.second == m - 1 || pos.second == 0) {
            cout << "YES" << bl << move.moves.size() << bl << move.moves << bl;
            return;
        }

        string path = move.moves;
        for (pair<char, ii> dir : directions) {
            ii d = dir.second;
            ii ud = {pos.first + d.first, pos.second + d.second};
            if (ud.first < 0 || ud.first >= n || ud.second < 0 || ud.second >= m || grid[ud.first][ud.second] == '#' || ~visited[ud.first][ud.second])
                continue;

            vii new_monsters_positions = generate_monsters_positions(monsters_pos);

            if (is_safe(ud, new_monsters_positions)) {
                queue.push({ud, path + dir.first, new_monsters_positions});
                visited[ud.first][ud.second] = 1;
            }
        }
    }

    cout << "NO" << bl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    fill(visited, -1);
    cin >> n >> m;
    grid = vs(n);
    FOR(i, n) cin >> grid[i];
    int x, y;
    FOR(i, n) FOR(j, m) {
        if (grid[i][j] == 'M') {
            monsters.push_back(mp(i, j));
        }
        if (grid[i][j] == 'A') {
            x = i;
            y = j;
        }
    }
    monstersCount = monsters.size();

    bfs(x, y);
    return 0;
}