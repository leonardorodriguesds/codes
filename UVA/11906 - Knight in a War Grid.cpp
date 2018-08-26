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
    int t, z = 0;
    scanf("%d", &t);
    while(t--){
        int r, c, m, n, w;
        scanf2(r, c);
        scanf2(m, n);
        scanf("%d", &w);
        if(r == 0 and m == 0){
            printf("Case %d: 0 0\n", ++z);
            continue;
        }
        int grid[r][c], inqueue[r][c], visited[r][c], even = 0, odd = 0;
        fill(grid, 0); fill(inqueue, -1);
        for(int i = 0; i < w; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            grid[a][b] = -1;
        }
        int dx[] = {-m, -m, m, m, -n, -n, n, n};
        int dy[] = {-n, n, -n, n, -m, m, -m, m};
        queue<ii> aux;
        aux.emplace(0, 0);
        inqueue[0][0] = 1;
        int x, y, u, v;
        while(!aux.empty()){
            fill(visited, -1);
            int count = 0;
            tie(x, y) = aux.front();
            aux.pop();
            for(int i = 0; i < 8; i++){
                u = x + dx[i], v = y + dy[i];
                if((u < 0 or u >= r or v < 0 or v >= c) or (!~grid[u][v])) continue;
                if(!~inqueue[u][v]) aux.emplace(u, v);
                if(!~visited[u][v]) count++;
                inqueue[u][v] = 1, visited[u][v] = 1;
            }
            if(count & 1) odd++;
            else even++;
        }
        printf("Case %d: %d %d\n", ++z, even, odd);
    }
    return 0;
}