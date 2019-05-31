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
#define max 100001
int n;
int a[max], p[max];
// int mem[max][1000001];

int dp(int i, int acc) {
    if (i >= n) return 0;
    int ans = 0;
    for(int j = i; j < n; j++)
        if (acc < a[i])
            ans = min((a[i] * p[i]) + (a[j] * p[i]) + dp(i + 1, acc + a[j]), (a[i] * p[i]) + dp(i + 1, acc));
        else
            ans += min(min((a[i] * p[i]) + (a[j] * p[i]) + dp(i + 1, acc + a[j]), a[i] * p[i] + dp(i + 1, acc)), 
                    min((a[j] * p[i]) + dp(i + 1, acc - a[i] + a[j]), dp(i + 1, acc - a[i])));
    return ans;
}

int main(){
    // fill(mem, INF);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i], &p[i]);
    printf("%d\n", dp(0, 0));
    return 0;
}