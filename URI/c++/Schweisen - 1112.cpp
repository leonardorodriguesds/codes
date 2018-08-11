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
#define uIndex(x, v)    (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)    (lower_bound(all(v), x) - v.begin())
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

template <class T> class FenwickTree2D{
    int n, m;
    T neutral;
    vector<vector<T>> ft;
    auto (*f)(T, T) -> T;

    public:
        FenwickTree2D(int n, int m, T neutral, T (*f)(T, T)): n(n), m(m), neutral(neutral){
            ft.assign(n + 1, vector<T>(m + 1, neutral));
            this->f = f;
        };
        T query(int i, int j){
            T ans = this->neutral;
            for(i++; i > 0; i -= (i & -i))
                for(int z = j + 1; z > 0; z -= (z & -z))
                    ans = this->f(ans, this->ft[i][z]);
            return ans;
        }
        T query(int x1, int y1, int x2, int y2){
            return (this->query(x2, y2) - this->query(x2, y1 - 1) - this->query(x1 - 1, y2) + this->query(x1 - 1, y1 - 1));
        }
        void update(int i, int j, T x){
            for(i++; i <= this->n; i += (i & -i))
                for(int z = j + 1; z <= this->m; z += (z & -z))
                    this->ft[i][z] = this->f(this->ft[i][z], x);
        };
};

int main(){
    int x, y, p, q;
    while(scanf("%d %d %d", &x, &y, &p) == 3){
        if(x == 0 and y == 0 and p == 0)
            break;
        FenwickTree2D<int> aux(x, y, 0, [](int a, int b)->int{ return (a + b); });
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            char a;
            int b, c, d, e;
            getchar();
            scanf("%c %d %d %d", &a, &b, &c, &d);
            if(a == 'A') aux.update(c, d, b);  
            else if(a == 'P'){
                scanf("%d", &e);
                printf("%d\n", (p * aux.query(min(b, d), min(c, e), max(b, d), max(c, e))));
            }
        }
        printf("\n");
    }
    return 0;
}