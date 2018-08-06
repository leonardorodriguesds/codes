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
#define d 256
#define pn 101
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
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int sum[n + 1], lookfor = 0, txt = 0, e = 1, j;
    string s, t;
    cin >> s >> t;
    fill(sum, 0);
    if(n >= m){
        for(int i = 0; i < m - 1; i++) e = ((e * d) % pn);
        for(int i = 0; i < m; i++)
            lookfor = (((d * lookfor) + t[i]) % pn), txt = (((d * txt) + s[i]) % pn);
        for(int i = 0; i <= n - m; i++){
            sum[i + 1] = sum[i];
            if(lookfor == txt){
                for(j = 0; j < m; j++) if(s[i + j] != t[j]) break;
                if(j == m) sum[i + 1] += 1;
            }
            if(i < n - m){
                txt = (d * (txt - (s[i] * e)) + s[i + m]) % pn;
                if(txt < 0) txt += pn;
            }
        }
    }
    for(int i = 0; i < q; i++){
        int a, b, ans = 0;
        scanf("%d %d", &a, &b);
        if(n >= m and b - a >= m - 2)
            ans = sum[b - m + 1] - sum[a - 1];
        printf("%d\n", ans);
    }
    return 0;
}