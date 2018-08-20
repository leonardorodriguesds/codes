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

int main(){
    int n, controll['z' - 'a' + 1];
    scanf("%d", &n);
    char aux[n];
    scanf("%s", aux);
    bool ans = n <= 1? true : false;
    fill(controll, 0);
    for(int i = 0; i < n and !ans; i++){
        if(controll[aux[i] - 'a'] == 0) controll[aux[i] - 'a'] = 1;
        else{
            ans = true;
            break;
        }
    }
    printf("%s\n", ans? "Yes" : "No");
    return 0;
}