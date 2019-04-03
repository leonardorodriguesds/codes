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
int n, p, qtd[21], timex[21], mem[21][32];

int solveIt() {
    fill(mem[0], 0);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= p; j++){
            if (j + qtd[i - 1] <= p and mem[i - 1][j + qtd[i - 1]] + timex[i - 1] > mem[i - 1][j])
                mem[i][j] = mem[i - 1][j + qtd[i - 1]] + timex[i - 1];
            else
                mem[i][j] = mem[i - 1][j];
        }
    return mem[n][0];
}

int main(){
    while(scanf("%d", &n) and n) {
        scanf("%d", &p);
        for(int i = 0; i < n; i++)
            scanf2(timex[i], qtd[i]);
        printf("%d min.\n", solveIt());
    }
    return 0;
}