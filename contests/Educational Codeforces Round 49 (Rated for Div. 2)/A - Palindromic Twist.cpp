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

int aux[] = {-1, 1};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        string s;
        scanf("%d", &n);
        cin >> s;
        bool ans = true;
        for(int i = 0; i < (n / 2) and ans; i++){
            ans = false;
            for(int j = 0; j < 2 and !ans; j++)
                for(int z = 0; z < 2 and !ans; z++)
                    ans = !ans && ((s[i] + aux[j]) == (s[n - (i + 1)] + aux[z]));
        }
        printf("%s\n", ans? "YES" : "NO");
    }
    return 0;
}