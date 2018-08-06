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
    while(true){
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0 and m == 0)
            break;
        bool ans = false;
        queue<ii> aux;
        aux.emplace(0, 1);
        int u, i;
        while(!(aux.empty())){
            tie(u, i) = aux.front();
            aux.pop();
            if(u == m){
                ans = true;
                break;
            }
            if(u - ((2 * i) - 1) > 0)
                aux.emplace(u - ((2 * i) - 1), i + 1);
            if(u + ((2 * i) - 1) <= n)
                aux.emplace(u + ((2 * i) - 1), i + 1);
        }
        printf("%s\n", ans? "Let me try!" : "Don't make fun of me!");
    }
    return 0;
}