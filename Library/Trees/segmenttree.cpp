#include <bits/stdc++.h>
using namespace std;
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))

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
        if(l > i or r < i) return;
        int mid = l + (r - l) / 2;
        if(l <= i and i <= mid) this->update(2 * sti + 1, l, mid, i, x);
        else this->update(2 * sti + 2, mid + 1, r, i, x);
        this->num[sti] = this->f(this->num[2 * sti + 1], this->num[2 * sti + 2]);
    }
    T query(int sti, int stl, int str, int l, int r){
        if(str < l or stl > r) return this->neutral;
        if(stl >= l and str <= r) return this->num[sti];
        int mid = stl + (str - stl) / 2;
        return this->f(this->query(2 * sti + 1, stl, mid, l, r), this->query(2 * sti + 2, mid + 1, str, l, r));
    }
    public:
        SegmentTree(int n, T neutral, T (*f)(T, T), T (*u)(T, T)): n(n){
            this->f = f, this->u = u, this->neutral = neutral;
            this->size = 2 * (int)pow(2, (int)(ceil(LOG2(n)))) - 1;
            num = vector<T>(this->size, neutral);
        };
        void update(int i, T x){
            return this->update(0, 0, this->n - 1, i, x);
        };
        T query(int l, int r){
            return this->query(0, 0, this->n - 1, l, r);
        };
};

int f(int a, int b){
    return a > b? a : b;
}
int u(int a, int b){
    return b;
}

int main(){
    int n, q, x;
    scanf("%d %d", &n, &q);
    SegmentTree<int> aux(n, 0, f, u);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        aux.update(i, x);
    }
    for(int i = 0; i < q; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1)
            printf("{%d <-> %d} => %d\n", b, c, aux.query(b, c));
        else
            aux.update(b, c);
    }
    return 0;
}