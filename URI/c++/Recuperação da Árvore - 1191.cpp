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

string solve(string prefixo, string infixo, vi& first_prefixo, vi& first_infixo) {
    if (prefixo.size() == 3) {
        char res[3] = {infixo[0], infixo[2], prefixo[0]};
        return string(res);
    } else {
        auto root = prefixo[0];
        auto left_infix = infixo.substr(0, infixo.find_first_of(root));
        auto right_infix = infixo.substr(infixo.find_first_of(root) + 1, infixo.size() - 1);
        auto left_prefix = prefixo.substr(1, prefixo.find_first_of(root));
        auto right_prefix = prefixo.substr(prefixo.find_first_of(root) + 1, prefixo.size() - 1);

        return string(solve(left_prefix, left_infix, first_prefixo, first_infixo).append(solve(right_prefix, right_infix, first_prefixo, first_infixo)));
    }
}

string init_problem(string prefixo, string infixo) {
    int i;
    vi first_prefixo('Z'-'A', -1), first_infixo('Z'-'A', -1);
    FOR(i, prefixo.size()) {
        first_prefixo[prefixo[i] - 'A'] = i; 
    }

    FOR(i, infixo.size()) {
        first_prefixo[prefixo[i] - 'A'] = i; 
    }

    return solve(prefixo, infixo, first_prefixo, first_infixo);
}

int main() {
    ios_base::sync_with_stdio(false); 
    string prefixo, infixo;
    while (cin >> prefixo >> infixo) {
        cout << init_problem(prefixo, infixo) << endl;
    }
    return 0;
}