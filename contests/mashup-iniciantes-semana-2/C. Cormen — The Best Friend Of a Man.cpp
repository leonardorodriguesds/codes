#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1)
#define CONDt(x, y, z)  ((x >= y)? x : z)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    vi walks(n, 0);
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        walks[i] = aux;
    }
    for (int i = 0; i < n - 1; i++){
        int current = (k - (walks[i] + walks[i + 1]));
        if(current <= 0)
            continue;
        walks[i + 1] += CONDt((k - (walks[i] + walks[i + 1])), 0, 0);
        walks[i] += CONDt((k - (walks[i] + walks[i + 1])), 0, 0);
        ans += current;
    }
    printf("%d\n", ans);
    for(int walk: walks)
        printf("%d ", walk);
    printf("\n");
    return 0;
}