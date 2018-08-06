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
    vii childs;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        childs.emplace_back((!(aux % m)? (aux / m): ((aux / m) + 1)), (i + 1));
    }
    sort(childs.begin(), childs.end(), greater<ii>());
    printf("%d\n", childs[0].second);
    return 0;
}