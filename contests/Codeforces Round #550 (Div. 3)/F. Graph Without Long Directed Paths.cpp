#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<pair<ii, int>> vpi;
typedef vector<string> vs;

vvi graph(2 * 100001);
int controll[2 * 100001];

bool solveIt(int i, int flag, int n) {
    if (i >= n) return false;
    controll[i] = flag;
    for (int x: graph[i])
        if (!~controll[x]) if (!solveIt(x, ((!flag)? 1 : 0), n)) return false;
        else if (controll[x] == flag) return false;
    return true;
}

int main(){
    fill(controll, -1);
    int n, m;
    scanf2(n, m);
    vii edges;
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf2(x, y);
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
        edges.emplace_back(x - 1, y - 1);
    }
    bool flag = solveIt(0, 0, n);
    cout << ((flag)? "Yes" : "No") << endl;
    if (flag) for(auto e: edges) cout << (controll[e.first] < controll[e.second]);
    cout << endl;
    return 0;
}