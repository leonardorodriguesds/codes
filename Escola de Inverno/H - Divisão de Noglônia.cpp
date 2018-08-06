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
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
        int x, y;
        scanf("%d %d", &x, &y);
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if (a > x and b > y)
                printf("NE\n");
            else if(a < x and b < y)
                printf("SO\n");
            else if(a > x and b < y)
                printf("SE\n");
            else if(b > y and a < x)
                printf("NO\n");
            else
                printf("divisa\n");
        }
    }
    return 0;
}