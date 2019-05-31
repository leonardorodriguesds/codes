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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    int aux[10001], aux2[10001];
    fill(aux, 0);
    fill(aux2, 0);
    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; j++) aux[j] = (i + 1);
    }

    int ans = 0;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j <= b; j++) aux2[j] = (i + 1);
    }

    for(int i = l; i <= r; i++)
        for(int z = 0; z < 1001; z++)
            if (aux2[z] > 0 and aux[z + i] > 0) {
                ans++;
                break;
            }

    cout << ans << endl;
    return 0;
}