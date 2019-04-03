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

int getReverseInt(int value) {
    int resultNumber = 0;
    for (int i = value; i != 0;) {
        int d = i / 10;
        resultNumber = (resultNumber - d) * 10 + i;
        i = d;
    }
    return resultNumber;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int initial, end;
        scanf("%d %d", &initial, &end);
        queue<ii> aux;
        aux.emplace(initial, 0);
        int u, dt, ans = 0;
        unordered_map<int, bool> controll;
        controll[initial] = true;
        while(!(aux.empty())){
            tie(u, dt) = aux.front();
            aux.pop();
            if((end - initial) <= dt){
                ans = (end - initial);
                break;
            }
            if(u == end){
                ans = dt;
                break;
            }
            controll[u + 1] = true;
            aux.emplace(u + 1, dt + 1);
            int rev = getReverseInt(u);
            if(!controll.count(rev))
                aux.emplace(getReverseInt(u), dt + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}