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
    string str, ans = "";
    cin >> str;
    int one = 0, j = -1, siz = sz(str);
    for(int i = 0; i < siz; i++)
        if(str[i] == '1') one++;
        else ans += str[i];
    siz = sz(ans);
    while(j + 1 < siz and ans[j + 1] == '0') ++j;
    ans.insert(j + 1, string(one, '1'));
    cout << ans << endl;
    return 0;
}