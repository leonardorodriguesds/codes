#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int n;
ll cards[10001];
ll table[10001];
ll dp(bool p, int i){
    if(i >= n)
        return 0;
    ll& ans = table[i];
    if(ans == -1){
        int aux = dp(!p, i + 1);
        for (int x = i + 1; x <= n; x++){
            if(!p)  table[i] = max(cards[i] + aux, cards[x] + aux);
            else    table[i] = min(cards[i] + aux, cards[x] + aux);
        }
    }
    return ans;
}

int main(){
    while(scanf("%d", &n)){
        fill(table, -1);
        for (int i = 0; i < n; i++){
            ll aux;
            scanf("%lld", &aux);
            cards[i] = aux;
        }
        printf("%lld\n", dp(false, 1));
    }
    return 0;
}