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
    int t;
    scanf("%d", &t);
    while(t--){
        int initial, end;
        scanf("%d %d", &initial, &end);
        queue<ii> aux;
        aux.emplace(initial, 0);
        int u, dt, ans = 0;
        while(!(aux.empty())){
            tie(u, dt) = aux.front();
            aux.pop();
            if(u == end){
                ans = dt;
                break;
            }
            aux.emplace(u + 1, dt + 1);
            if(u == 0 or u < 12)
                continue;
            int rev;
            ostringstream convert; 
            convert << u;
            string temp = convert.str();
            if(temp[0] > temp[sz(temp) - 1])
                continue;
            reverse(all(temp));
            istringstream buf(temp);
            buf >> rev;
            if(rev > u)
                aux.emplace(rev, dt + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}