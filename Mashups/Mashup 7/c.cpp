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
    cin >> n;
    array<int, 3> cash = {0, 0, 0};
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        if (a == 50 and cash[0] > 0) cash[1]++, cash[0]--;
        else if (a == 100 and ((cash[0] > 0 and cash[1] > 0) or (cash[0] > 2))){
            cash[2]++;
            if (cash[0] > 0 and cash[1] > 0) cash[0]--, cash[1]--;
            else cash[0] -= 3;
        } else if (a == 25) cash[0]++;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}