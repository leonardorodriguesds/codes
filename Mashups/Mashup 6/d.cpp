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

int m;
auto pos_func = [](int x) { return abs(((double)m + (double)1) / 2.0 - x); };

struct Bascket {
    int balls, i;

    bool operator < (Bascket other) const {
        if (other.balls != balls) return balls > other.balls;
        double pos_this = pos_func(i), pos_other = pos_func(other.i);
        return (pos_this != pos_other)? (pos_this > pos_other) : (i > other.i);
    }
};

int main(){
    int n;
    cin >> n >> m;
    priority_queue<Bascket> aux;
    for(int i = 0; i < m; i++){
        Bascket x;
        x.balls = 0;
        x.i = i + 1;
        aux.push(x);
    }

    for(int i = 0; i < n; i++){
        Bascket x = aux.top();
        aux.pop();
        cout << x.i << endl;
        x.balls++;
        aux.push(x);
    }
    return 0;
}