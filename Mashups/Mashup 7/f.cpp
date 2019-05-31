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
    int n;
    vi coins;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        coins.push_back(a);
    }

    int l = -1, r = -1, j;
    bool flag = false;
    for(j = 0; j < n; j++){
        if (coins[j] != j + 1) {
            flag = (!~r) & (!~l);
            if (!flag) break;
            l = j, r = coins[j] - 1;
            
            for(int z = 0; z <= (r - j) and flag; z++)
                flag &= (coins[r - z] == (j + 1 + z));

            if (!flag) break;
            else j = r + 1;
        }
    }

    if (flag) cout << l + 1 << " " << r + 1 << endl;
    else cout << 0 << " " << 0 << endl;
    return 0;
}