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

int main(){
    int n, k;
    while(scanf2(n, k)){
        SegmentTree<int> aux(n, 1, [](int a, int b)->int{ return a * b; }, [](int a, int b)->int{ return b; });
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            aux.update(i, x);
        }
        while(k--){
            getchar();
            char c;
            int i, j;
            cin >> c >> i >> j;
            if(c == 'P'){
                int ans = aux.query(i - 1, j - 1);
                printf("%c", ans == 0? '0' : ((ans > 0)? '+' : '-'));
            } else aux.update(i - 1, j);
        }
        cout << endl;
    }
    return 0;
}