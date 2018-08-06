#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
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
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int n;
    scanf("%d", &n);
    vi even;
    vi odd;
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        if(aux & 1)
            odd.push_back(aux);
        else
            even.push_back(aux);
    }
    sort(all(even));
    sort(all(odd), greater<int>());
    for(int e: even)
        printf("%d\n", e);
    for(int e: odd)
        printf("%d\n", e);
    return 0;
}