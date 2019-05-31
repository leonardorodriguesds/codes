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
    string str1, str2, ans = "";
    cin >> str1 >> str2;
    while (n--)
        if ((str2[n] >= str1[n])) ans += ceil((double)((str2[n] + str1[n]) / 2.0));
        else {
            int x = ceil((double)((('z' - str2[n]) + str1[n] - 'a') / 2.0));
            ans += (('z' - str2[n]) > x)? str2[n] + x : 'a' + x - ('z' - str2[n] + 1);
        }

    reverse(all(ans));
    cout << ans << endl;
    return 0;
}