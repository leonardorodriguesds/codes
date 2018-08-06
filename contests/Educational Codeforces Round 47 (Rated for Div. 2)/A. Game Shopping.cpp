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
    int games[n], ans = 0, j = 0;
    for(int i = 0; i < n; i++) scanf("%d", &games[i]);
    for(int i = 0; i < m and j < n; i++){
        int bill;
        scanf("%d", &bill);
        while(j < n and bill < games[j]) j++;
        if(j < n) ans++, j++;
    }
    printf("%d\n", ans);
    return 0;
}