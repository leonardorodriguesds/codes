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
#define mod 1000000
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

vector<vector<ll>> matrix_times(vector<vector<ll>> first, vector<vector<ll>> second){
    vector<vector<ll>> ans(first.size(), vector<ll>(second[0].size()));
    for(int i = 0; i < first.size(); i++){
        for(int z = 0; z < second[0].size(); z++){
            ll aux = 0;
            for(int j = 0; j < first[i].size(); j++)
                aux += (first[i][j] * second[j][z]), aux %= mod;
            ans[i][z] = aux;
        }
    }
    return ans;
}

vector<vector<ll>> fast_exp(vector<vector<ll>> base, ll exp){
    if(exp == 1)
        return base;
    vector<vector<ll>> aux = fast_exp(base, (exp / 2));
    aux = matrix_times(aux, aux);
    return ((exp & 1))? matrix_times(base, aux) : aux;
}

ll solveIt(ll n, ll k, ll l){
    vector<vector<ll>> ans(2, vector<ll>(2, 0));
    ans[0][0] = 0, ans[0][1] = 1, ans[1][0] = l, ans[1][1] = k;
    ans = fast_exp(ans, n / 5);
    return ans[1][1];
}

int main(){
    ll n, k, l;
    while(scanf("%lld %lld %lld", &n, &k, &l) == 3)
        printf("%06lld\n", solveIt(n, k, l));
    return 0;
}