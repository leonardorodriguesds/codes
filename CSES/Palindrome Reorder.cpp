#include <bits/stdc++.h>
#define DEBUG false
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
#define fill(t,v)       memset(t, v, sizeof(t))
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

void init_problem(int n) {
    
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    string str; cin >> str;

    vi count = vi('Z' - 'A', 0);
    
    for (char c: str)
        count[c - 'A']++;

    int odd = -1;
    FOR(i, 'Z' - 'A')
        if (count[i] % 2 != 0) {
            if (!~odd)
                odd = i;
            else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }

    /* FOR(i, 'Z' - 'A')
        cout << (char)(i +  'A') << " = " << count[i] << endl;
    cout << "odd = " << odd << endl;  */

    int n = str.size();
    if (n % 2 == 0 && ~odd) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    vector<char> res = vector<char>(str.size());
    res[n / 2] = odd + 'A';
    int j = 0;
    FOR(i, n / 2){
        while(count[j] < 2)
            j++;

        res[i] = res[n - i - 1] = j + 'A';
        count[j] -= 2;
    }

    for(char c: res)
        cout << c;
    cout << endl;
    return 0;
}