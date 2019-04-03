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
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;

int main(){
    int n, sa = 0, sb = 0;
    scanf("%d", &n);
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
    sort(all(b)); sort(all(a));
    while(!(a.empty() and b.empty())){
        if(a.empty() or a.back() < b.back()) b.pop_back();
        else sa += a.back(), a.pop_back();
        if(!a.empty() and (b.empty() or b.back() < a.back())) a.pop_back();
        else sb += b.back(), b.pop_back();
    }
    printf("%d\n", sa - sb);
    return 0;
}