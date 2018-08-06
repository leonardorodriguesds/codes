#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int l[1001][1001], r[1001][1001], u[1001][1001], d[1001][1001];
int h[1001][1001], v[1001][1001];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vs grid(n), c(n, string(m, '.'));
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    int ans = 0;
    vector<pair<ii, int>> aux;
    for(int i = 0; i < n; i++){
        int lcount = 0, rcount = 0;
        for(int j = 0; j < m; j++){
            l[i][j] = lcount;
            if(grid[i][j] == '*') lcount++;
            else lcount = 0;
        }
        for(int j = m - 1; j >= 0; j--){
            r[i][j] = rcount;
            if(grid[i][j] == '*') rcount++;
            else rcount = 0;
        }
    }
    for(int j = 0; j < m; j++){
        int ucount = 0, dcount = 0;
        for(int i = 0; i < n; i++){
            u[i][j] = dcount;
            if(grid[i][j] == '*') dcount++;
            else dcount = 0;
        }
        for(int i = n - 1; i >= 0; i--){
            d[i][j] = ucount;
            if(grid[i][j] == '*') ucount++;
            else ucount = 0;
        }
    }
    fill(h, 0);
    fill(v, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int dxy = min(min(u[i][j], d[i][j]), min(l[i][j], r[i][j]));;
            if(grid[i][j] == '*' and dxy > 0){
                v[i - dxy][j] = max(v[i - dxy][j], 2 * dxy + 1);
                h[i][j - dxy] = max(h[i][j - dxy], 2 * dxy + 1);
                ans++;
                aux.emplace_back(make_pair(i, j), dxy);  
            }
        }
    }
    for(int i = 0; i < n; i++){
        int dv = 0;
        for(int j = 0; j < m; j++){
            dv = max(dv - 1, h[i][j]);
            if(dv > 0)
                c[i][j] = '*';
        }
    }
    for(int j = 0; j < m; j++){
        int dv = 0;
        for(int i = 0; i < n; i++){
            dv = max(dv - 1, v[i][j]);
            if(dv > 0)
                c[i][j] = '*';
        }
    }
    /* for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << c[i][j];
        cout << endl;
    } */
    if(c == grid){
        printf("%d\n", ans);
        for(auto e: aux)
            printf("%d %d %d\n", e.first.first + 1, e.first.second + 1, e.second);
    } else
        printf("-1\n");
    return 0;
}