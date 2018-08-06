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
    int x, y, i, j;
    while(true){
        scanf("%d %d %d %d", &x, &y, &i, &j);
        if(x == 0 and y == 0 and i == 0 and j == 0)
            break;
        int ans = (x != i or y != j)? 1 : 0;
        if((x != i and y != j) and !(x == i or y == j or abs(x - i) == abs(y - j)))
            ans++;
        printf("%d\n", ans);
    }
    return 0;
}