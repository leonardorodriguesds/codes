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
    scanf("%d", &n);
    while(n--) {
        char opt;
        int x1, y1, x2, y2, x, y, gcd;
        scanf("%d / %d %c %d / %d", &x1, &y1, &opt, &x2, &y2);
        switch(opt) {
            case '+': {
                y = (y1 * y2);
                x = (x1 * y2 + x2 * y1) * (y < 0? -1 : 1);
                y = y < 0? -y : y;
                gcd = __gcd(x, y);
                gcd = gcd < 0 ? -gcd : gcd;
                printf("%d/%d = %d/%d\n", x, y, x / gcd, y / gcd);
                break;
            }
            case '-': {
                y = (y1 * y2);
                x = (x1 * y2 - x2 * y1) * (y < 0? -1 : 1);
                y = y < 0? -y : y;
                gcd = __gcd(x, y);
                gcd = gcd < 0 ? -gcd : gcd;
                printf("%d/%d = %d/%d\n", x, y, x / gcd, y / gcd);
                break;
            }
            case '*': {
                y = (y1 * y2);
                x = (x1 * x2) * (y < 0? -1 : 1);
                y = y < 0? -y : y;
                gcd = __gcd(x, y);
                gcd = gcd < 0 ? -gcd : gcd;
                printf("%d/%d = %d/%d\n", x, y, x / gcd, y / gcd);
                break;
            }
            case '/': {
                y = (y1 * x2);
                x = (x1 * y2) * (y < 0? -1 : 1);
                y = y < 0? -y : y;
                gcd = __gcd(x, y);
                gcd = gcd < 0 ? -gcd : gcd;
                printf("%d/%d = %d/%d\n", x, y, x / gcd, y / gcd);
            }
        }
    }
    return 0;
}