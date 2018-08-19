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
#define uIndex(x, v)    (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)    (lower_bound(all(v), x) - v.begin())
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
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
ii table[100001][2];
int n, happiness[100001], controll[100001][2];
vvi graph(100001, vi());

ii solveIt(int i, int f){
    if(i >= n) return make_pair(0, 0);
    ii& ans = table[i][f];
    if(!~controll[i][f]){
        ii aux1, aux2;
        aux1 = make_pair(0, 0), aux2 = make_pair(0, 0);
        for(int v: graph[i]){
            ii temp1 = solveIt(v, 0);
            aux1.first += temp1.first, aux1.second += temp1.second;
            if(!f){
                ii temp2 = solveIt(v, 1);
                aux2.first += temp2.first, aux2.second += temp2.second;
            }
        }
        ans.first = max(aux1.first, aux2.first + (!f)? happiness[i] : 0);
        ans.second = max(aux1.second, aux2.second + (!f)? happiness[i] : 0);
        controll[i][f] = 1;
    }
    return ans;
}

int main(){
    fill(controll, -1);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &happiness[i]);
    for(int i = 1; i < n; i++){
        int a;
        scanf("%d", &a);
        graph[a - 1].push_back(i);
    }
    ii ans = solveIt(0, 0);
    printf("%d\n", max(ans.first, ans.second));
    return 0;
}