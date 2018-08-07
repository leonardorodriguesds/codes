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
    string base;
    while(cin >> base){
        int i = 0;
        vii controll;
        for(char u: base){
            if(i and controll[i - 1].first == u)
                controll[i - 1].second++;
            else{
                controll.emplace_back(u, 1);
                i++;
            }
        }
        stringstream ans;
        for(auto e: controll)
            ans << (char)e.first << (e.second);
        if(sz(ans.str()) < sz(base))
            cout << ans.str() << endl;
        else
            cout << base << endl;
    }
    return 0;
}