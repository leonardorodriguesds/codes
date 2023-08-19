#include <bits/stdc++.h>
#include <sys/resource.h>
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

void setstack( void )
{
  const rlim_t kStackSize = 64L * 1024L * 1024L;   // min stack size = 64 Mb
  struct rlimit rl;
  int result = getrlimit( RLIMIT_STACK, &rl);
  if( result == 0 && rl.rlim_cur < kStackSize )
  {
    rl.rlim_cur = kStackSize;
    result = setrlimit( RLIMIT_STACK, &rl);
    if( result != 0 )
      fprintf(stderr, "setrlimit returned result = %d\n", result);
  }
}

int n, m;
char draw[1024][1024];

void fill_draw(int i, int j) {
    if (i < 0 || j < 0 || i > n || j > m)
        return;
    if (draw[i][j] == '.') {
        draw[i][j] = '0';
        fill_draw(i - 1, j);
        fill_draw(i + 1, j);
        fill_draw(i, j - 1);
        fill_draw(i, j + 1);
    }
}

void init_problem() {
    FOR(i, n) {
        cin >> draw[i];
    }

    int res = 0;
    FOR(i, n) {
        FOR(j, m) {
            if (draw[i][j] == '.') {
                res++;
                fill_draw(i, j);
            }
        }
    }
    cout << res << endl;
}
 
int main() {
    setstack();
    ios_base::sync_with_stdio(false); 
    cin >> n >> m;
    init_problem();
    return 0;
}