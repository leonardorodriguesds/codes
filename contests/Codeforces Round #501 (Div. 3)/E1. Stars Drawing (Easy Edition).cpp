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

int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vs grid;
int siz[101][101];

int main(){
    scanf("%d %d", &n, &m);
    fill(siz, -1);
    grid = vs(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    int ans = 0;
    for(int i = 1; i + 1 < n; i++){
        for(int j = 1; j + 1 < m; j++){
            if(grid[i][j] == '*'){
                bool flag = true;
                for(int z = 0; z < 4; z++)
                    flag = flag && (grid[i + dx[z]][j + dy[z]] == '*');
                if(flag){
                    int& ssiz = siz[i][j];
                    ssiz = INF;
                    for(int z = 0; z < 4; z++){
                        int x = i + dx[z], y = j + dy[z], count = 0;
                        while((x >= 0 and x < n) and (y >= 0 and y < m) and (grid[x][y] == '*'))
                            count++, x += dx[z], y += dy[z];
                        ssiz = min(ssiz, count);
                    }
                    ans++;
                }
            }
        }
    }
    vs c(n, string(m, '.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(siz[i][j] > 0){
                for(int z = 0; z < 4; z++){
                    int x = i, y = j, k = siz[i][j] + 1;
                    while((k--) and (x >= 0 and x < n) and (y >= 0 and y < m))
                        c[x][y] = '*', x += dx[z], y += dy[z];
                }
            }
        }
    }
    /* for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << c[i][j];
        cout << endl;
    } */
    if(c == grid){
        printf("%d\n", ans);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(siz[i][j] > 0)
                    printf("%d %d %d\n", i + 1, j + 1, siz[i][j]);
            }
        }
    } else
        printf("-1\n");
    return 0;
}