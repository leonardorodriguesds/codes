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
    int n, m, z = 0;
    scanf("%d %d", &n, &m);
    if (m < n - 1){
		puts("Impossible");
		return 0;
	}
    ii ans[m];
    for(int i = 0; (i < n); i++)
        for(int j = i + 1; (j < n) and (z < m); j++)
            if(__gcd(i + 1, j + 1) == 1) ans[z++] = make_pair(j + 1, i + 1);
    if(z < m) printf("Impossible\n");
    else{
        printf("Possible\n");
        for(auto e: ans)
            printf("%d %d\n", e.first, e.second);
    }
    return 0;
}