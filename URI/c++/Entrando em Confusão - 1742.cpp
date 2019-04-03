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
int grid[1001][1001];
int n, m, h;

int solveit(int x, int y, int xf, int yf, int z){
    int ans = 0;
    if(x < 0 or xf < 0 or y < 0 or yf < 0 or x > n or xf > n or y > m or yf > m) return 0;
    if(x == xf and y == yf) return 1;
    if(!~grid[x][y] or grid[x][y] == z) return 0;
    grid[x][y] = z;
    ans += solveit(x + 1, y, xf, yf, z);
    ans += solveit(x, y + 1, xf, yf, z);
    ans += solveit(x - 1, y, xf, yf, z);
    ans += solveit(x, y - 1, xf, yf, z);
    return ans;
}

int main(){
    while(scanf3(n, m, h)){
        fill(grid, 0);
        while(h--){
            int x, y1, x2, y2;
            scanf2(x, y1), scanf2(x2, y2);
            while(x <= x2){
                int y = y1;
                while(y <= y2)
                    grid[x][y] = -1, y++;
                x++;
            }
        }
        int q;
        scanf("%d", &q);
        while(q--){
            int x1, y1, x2, y2;
            scanf2(x1, y1), scanf2(x2, y2);
            printf("%d\n", solveit(x1, y1, x2, y2, q + 1));
        }
        printf("\n");
    }
    return 0;
}