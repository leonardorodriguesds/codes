#include <bits/stdc++.h>
#include <iomanip>
#define DEBUG true
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill_arr(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
#define debugarr(arr) if (DEBUG) for(auto x: arr) cout << x << " "; cout << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

/* long precision = 10000;
long doubleParaLongCom4CasasDecimais(double valor) {
    return static_cast<long>(valor * precision);
}

double longParaDoubleCom4CasasDecimais(long valorLong) {
    return static_cast<double>(valorLong) / precision;
} */

int tamanho = 10^5 + 1;
double pre[100001];

double binary_search(double l, double r, double a, vector<double>& arr) {
    int n = arr.size();
    while (l <= r) {
        double m = (l + r) / 2.0;
        int i = (int)(lower_bound(all(arr), m) - arr.begin());
        auto res = pre[n - 1];
        if (i > 0) {
            res = pre[n - 1] - pre[i - 1];
        }
        res = res - ((n - i) * m);
        // #ifndef ONLINE_JUDGE
        //     std::cout << std::fixed << std::setprecision(4);
        //     cout << l << "<>" << r << " :: [" << m << "] " << res << " == " << a << " (" << i << ", " << arr[i] << ", " << n << ", " << pre[n - 1] << "-" << (i > 0 ? pre[i - 1] : 0) << " - " << (n - i) * m << ")" << endl; 
        // #endif
        if (fabs(res - a) < EPS) {
            // cout << "<====>" << endl;
            return m;
        }

        if (res > a) {
            // cout << "<====" << endl;
            l = m;
        } else {
            // cout << "====>" << endl;
            r = m;
        }
    }
    return 0;
}

void init_problem(int n, int a) {
    vector<double> arr(n);
    FOR(i, n) {
        double c;
        cin >> c;
        // cout << i << " -- " << c << endl;
        arr[i] = c;
    }


    sort(all(arr));
    // debugarr(arr);
    fill(pre, pre + tamanho, 0);
    
    pre[0] = arr[0];
    FOR1(i, n - 1) {
        pre[i] = arr[i] + pre[i - 1];
    }

    // debugarr(pre);

    if (pre[n - 1] < (double)a) {
        cout << "-.-" << endl;
        return;
    }
    
    auto res = binary_search(0, arr[n - 1] + 1, (double)a, arr);
    // cout << "==> " << res << endl;
    if (res < 0.0001) {
        cout << ":D" << endl;
    } else {
        std::cout << std::fixed << std::setprecision(4);
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    int n, a;
    while (cin >> n >> a) {
        if (n == 0 && a == 0) {
            break;
        }
        // cout << n << "<>" << a << endl;
        init_problem(n, a);
    }
    return 0;
}