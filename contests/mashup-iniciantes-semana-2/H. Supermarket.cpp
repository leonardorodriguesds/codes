#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    vector<double> prices;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        prices.push_back((double)((double)a * (m / (double)b)));
    }
    sort(prices.begin(), prices.end());
    printf("%.8lf\n", prices[0]);
    return 0;
}