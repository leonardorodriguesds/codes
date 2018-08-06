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

template <class T> class FenwickTree{
    int n;
    T neutral;
    vector<T> ft;
    auto (*f)(T, T) -> T;
    auto (*u)(T, T) -> T;

    public:
        FenwickTree(int n, T neutral, T (*f)(T, T), T (*u)(T, T)): n(n), neutral(neutral){
            ft.assign(n + 1, neutral);
            this->f = f, this->u = u;
        };
        FenwickTree(vector<T>& e, T neutral, T (*f)(T, T), T (*u)(T, T)): n(e.size()), neutral(neutral){
            ft.assign(n + 1, neutral);
            this->f = f, this->u = u;
            for(int i = 0; i < n; i++)
                this->update(i, e[i]);
        };
        T query(int i){
            T ans = this->neutral;
            for(i++; i > 0; i -= (i & -i))
                ans = this->f(ans, this->ft[i]);
            return ans;
        };
        T query(int i, int j){
            return this->query(j) - this->query(i - 1);
        };
        void update(int i, T x){
            for(i++; i <= this->n; i += (i & -i))
                this->ft[i] = this->u(this->ft[i], x);
        };
};

int f(int a, int b){
    return (a + b);
}

int main(){
    int n;
    scanf("%d", &n);
    vi num(n, 0);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    FenwickTree<int> aux(num, 0, f, f);
    getchar();
    char a;
    int b;
    while(scanf("%c %d", &a, &b) == 2){
        if(a == 'a') aux.update(b - 1, -num[b - 1]);
        else if(a == '?') printf("%d\n", aux.query(b - 1) - num[b - 1]);
        getchar();
    }
    return 0;
}