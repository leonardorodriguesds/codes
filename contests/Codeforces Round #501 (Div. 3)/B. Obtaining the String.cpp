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
    string s, t;
    cin >> s >> t;
    if(sz(s) != sz(t)){
        printf("-1\n");
        return 0;
    }
    int count[30];
    fill(count, 0);
    for(int i = 0; i < n; i++)
        count[s[i] - 'a']++;
    for(int i = 0; i < n; i++){
        count[t[i] - 'a']--;
        if(count[t[i] - 'a'] < 0){
            printf("-1\n");
            return 0;
        }
    }
    int ans = 0;
    vi pos;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == t[i]) continue;
        int z = i;
        while(s[z] != t[i]) z++;
        for(int j = z - 1; j >= i; --j){
            pos.push_back(j + 1);
            ans++;
            swap(s[j], s[j + 1]);
        }
    }
    printf("%d\n", ans);
    for(int u: pos)
        printf("%d ", u);
    printf("\n");
    return 0;
}