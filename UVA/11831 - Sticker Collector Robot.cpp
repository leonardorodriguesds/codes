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
typedef vector<string> vs;

int main(){
    int dxy[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};      //L, N, O, S
    int tdx[4][2] = {{3, 1}, {0, 2}, {1, 3}, {2, 0}};   //L, N, O, S
    int n, m, s, d;
    while(scanf3(n, m, s) and n != 0 and m != 0 and s != 0){
        char grid[n + 1][m + 1];
        int ans = 0, x = 0, y = 0;
        for(int i = 0; i < n; i++){
            cin >> grid[i];
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 'L' or grid[i][j] == 'O' or grid[i][j] == 'N' or grid[i][j] == 'S')
                    x = i, y = j, d = grid[i][j];
        }
        d = (d == 'L')? 0 : (d == 'N')? 1: (d == 'O')? 2: 3;
        string controll;
        cin >> controll;
        for(char c: controll){
            if(c == 'D' or c == 'E'){
                d = tdx[d][c - 'D'];
                continue;
            }
            x += dxy[d][0], y += dxy[d][1];
            if((x < 0 or x >= n or y < 0 or y >= m) or (grid[x][y] == '#')) x -= dxy[d][0], y -= dxy[d][1];
            else if(grid[x][y] == '*') ans++, grid[x][y] = '.';
        }
        printf("%d\n", ans);
    }
    return 0;
}