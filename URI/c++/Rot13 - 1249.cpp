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
    string line;
    while (getline(cin, line)) {
        size_t n = line.size();
        for(size_t i = 0; i < n; i++){
            if (line[i] >= 'a' and line[i] <= 'z'){
                if (line[i] + 13 > 'z') line[i] = 'a' + (13 - ('z' - line[i] + 1));
                else line[i] += 13;
            }
            if (line[i] >= 'A' and line[i] <= 'Z'){
                if (line[i] + 13 > 'Z') line[i] = 'A' + (13 - ('Z' - line[i] + 1));
                else line[i] += 13;
            }
        }
        cout << line << endl;
    }
    return 0;
}