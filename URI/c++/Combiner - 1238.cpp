#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
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
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string lhs, rhs, ans = "";   
        cin >> lhs >> rhs;
        int s = sz(lhs), f = sz(rhs);
        int z = 0;
        for(int i = 0; i < s + f; i++){
            ans += (i & 1 and f > z)? rhs[z] : (s > z)? lhs[z] : rhs[z];
            if(i & 1 or f <= z or s <= z) z++;
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}