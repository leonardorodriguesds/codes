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

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int aux[m + 1], ans = 0;
    vi points;
    fill(aux, 0);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        aux[a]++;
        aux[b + 1]--;
    }
    int amount = 0;
    for(int i = 1; i <= m; i++){
        amount += aux[i];
        if(amount == 0){
            ans++;
            points.push_back(i);  
        }  
    }
    printf("%d\n", ans);
    for(int u: points)
        printf("%d ", u);
    printf("\n");
    return 0;
}