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

template <class T> class SegmentTree{
    int n, size;
    T neutral;
    vector<T> num;
    auto (*f)(T, T) -> T;
    auto (*u)(T, T) -> T;

    void update(int sti, int l, int r, int i, T x){
        if(l == r and l == i){
            this->num[sti] = this->u(this->num[sti], x);
            return;
        }
        if(l > i or r < i)
            return;
        int mid = l + (r - l) / 2;
        this->update(2 * sti + 1, l, mid, i, x);
        this->update(2 * sti + 2, mid + 1, r, i, x);
        this->num[sti] = this->f(this->num[2 * sti + 1], this->num[2 * sti + 2]);
    }
    T query(int sti, int stl, int str, int l, int r){
        if(str < l or stl > r)
            return this->neutral;
        if(stl >= l and str <= r)
            return this->num[sti];
        int mid = stl + (str - stl) / 2;
        return this->f(this->query(2 * sti + 1, stl, mid, l, r), this->query(2 * sti + 2, mid + 1, str, l, r));
    }
    public:
        SegmentTree(int n, T neutral, T (*f)(T, T), T (*u)(T, T)): n(n){
            this->f = f, this->u = u, this->neutral = neutral;
            this->size = 2 * (int)pow(2, (int)(ceil(log2(n)))) - 1;
            num = vector<T>(this->size, 0);
        };
        void update(int i, T x){
            return this->update(0, 0, this->n - 1, i, x);
        };
        T query(int l, int r){
            return this->query(0, 0, this->n - 1, l, r);
        };
};

ll f(ll a, ll b){
    return (a | b);
}
ll u(ll a, ll b){
    return b;
}

int main(){
    int n, q, m, a;
    scanf("%d %d %d", &n, &q, &m);
    SegmentTree<ll> aux(n, 0, f, u);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        aux.update(i, (1LL << (a - 1)));
    }
    for(int i = 0; i < q; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        if(a == 1) printf("%d\n", (int)__builtin_popcountll(aux.query(b - 1, w - 1)));
        else if(a == 2) aux.update(b - 1, (1LL << (w - 1)));
    }
    return 0;
}