#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
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

int f(int a, int b){
    return (a + b);
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        FenwickTree2D<int> aux(n, n, 0, f);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int a;
                scanf("%d", &a);
                aux.update(i, j, a);
            }
        }
        for(int i = 0; i < m; i++){
            int x, y, a, b;
            scanf("%d %d", &x, &y);
            aux.update(x - 1, y - 1, 1);
            scanf("%d %d %d %d", &x, &y, &a, &b);
            printf("%d\n", aux.query(x - 1, y - 1, a - 1, b - 1));
        }
    }
    return 0;
}