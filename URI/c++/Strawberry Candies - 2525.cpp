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
int n, m;
int packages[1001];
int table[1001][1001];

int solveIt(int i, ll accumulator, int accum){
    if(i >= m){
        cout << accumulator << " <=> " << accum << endl;
        return ((!(accumulator % n))? accum : -INF);
    }
    int& ans = table[i][(accumulator % n)];
    if(ans == -1){
        ans = max(0, solveIt(i + 1, accumulator + packages[i], accum + 1)); 
        ans = max(ans, solveIt(i + 1, accumulator, accum));
    }
    return ans;
}

int main(){
    while(scanf("%d %d", &n, &m) == 2){
        fill(table, -1);
        for (int i = 0; i < m; i++){
            int aux;
            scanf("%d", &aux);
            packages[i] = aux;
        }
        printf("%d\n", solveIt(0, 0, 0));
    }
    return 0;
}