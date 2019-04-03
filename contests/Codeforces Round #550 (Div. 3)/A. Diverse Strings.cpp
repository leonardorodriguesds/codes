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
    while (n--) {
        string str;
        cin >> str;
        if ((int)str.size() == 1) {
            cout << "Yes" << endl;
            continue;
        } else if ((int)str.size() > 'z' - 'a' + 1) {
            cout << "No" << endl;
            continue;
        }
        bool ans = true;
        int letters = 0;
        sort(all(str));
        for (int i = 0; ((i < (int)str.size()) and ans); i++)
            if (letters & 1 << (str[i] - 'a')) ans = false;
            else {
                if (i) ans &= ((str[i] - str[i - 1]) == 1);
                letters |= 1 << (str[i] - 'a');
            }

        printf("%s\n", (ans)? "Yes" : "No");
    }
    return 0;
}