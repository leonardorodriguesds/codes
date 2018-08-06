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
    int n;
    scanf("%d", &n);
    vi ans(n, 0);
    map<int, vi> controll;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        controll[a].push_back(i);
    }
    for(auto e: controll){
        for(auto u: e.second){
            int aux = e.first;
            if(!(e.first & 1))
                aux--;
            ans[u] = aux;
        }
    }
    for(int e: ans)
        printf("%d ", e);
    printf("\n");
    return 0;  
}