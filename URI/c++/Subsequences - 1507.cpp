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

bool SolveIt(int i, int j, string base, int n, string aux, int x){
    if(i >= n or j >= x)
        return (j >= x)? true : false;
    if(base[i] == aux[j])
        return SolveIt(i + 1, j + 1, base, n, aux, x);
    return SolveIt(i + 1, j, base, n, aux, x);
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    while(n--){
        string base;
        cin >> base;
        int q, sz = sz(base);
        scanf("%d", &q);
        while(q--){
            string aux;
            cin >> aux;
            int z = sz(aux);
            printf("%s\n", (((sz > z and SolveIt(0, 0, base, sz, aux, z)) or
            (sz == z and base == aux))? "Yes" : "No"));
        }
    }
    return 0;
}