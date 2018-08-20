#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)    (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)    (lower_bound(all(v), x) - v.begin())
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
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
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        map<int, int> aux;
        ll controll = INFLL;
        ii ans;
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            aux[a] += 1;
        }
        map<int, int>::iterator it, jt;
        for(it = aux.begin(); it != aux.end(); ++it){
            if((*it).second < 2) continue;
            jt = it;
            if((*it).second < 4) while(++jt != aux.end() and (*jt).second < 2){}
            if((*jt).second < 2) continue;
            int x = (*it).first, y = (*jt).first;
            ll temp = (((2 * (x + y)) * (2 * (x + y))) / (x * y));
            if(temp < controll){
                ans = make_pair((*it).first, (*jt).first);
                controll = temp;
            }
        }
        printf("%d %d %d %d\n", ans.first, ans.first, ans.second, ans.second);
    }
    return 0;
}