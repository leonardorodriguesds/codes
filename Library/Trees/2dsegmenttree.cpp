#include <bits/stdc++.h>
using namespace std;
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))

template <class T> class SegmentTree2D{
    int n, m, sizen, sizem;
    T neutral;
    vector<vector<T>> st;
    auto (*f)(T, T) -> T;
    auto (*u)(T, T) -> T;

    void updatex(int sti, int l, int r, int i, int node, T x){
        if(l == r and l == i){
            this->st[node][sti] = this->u(this->st[node][sti], x);
            return;
        }
        if(l > i or r < i) return;
        int mid = l + (r - l) / 2;
        if(l <= i and i <= mid) this->updatex(2 * sti + 1, l, mid, i, node, x);
        else this->updatex(2 * sti + 2, mid + 1, r, i, node, x);
        this->st[node][sti] = this->f(this->st[node][2 * sti + 1], this->st[node][2 * sti + 2]);
    }
    void update(int sti, int l, int r, int i, vector<T>& a){
        if(l == r and l == i){
            for(int j = 0; j < this->m; j++)
                this->updatex(0, 0, this->m - 1, j, sti, a[j]);
            return;
        }
        if(l > i or r < i) return;
        int mid = l + (r - l) / 2;
        if(l <= i and i <= mid) this->update(2 * sti + 1, l, mid, i, a);
        else this->update(2 * sti + 2, mid + 1, r, i, a);
        for(int z = 0; z < this->m; z++)
            this->st[sti][z] = this->f(this->st[2 * sti + 1][z], this->st[2 * sti + 2][z]);
    }
    void update(int sti, int l, int r, int i, int j, T x){
        if(l == r and l == i)
            return this->updatex(0, 0, this->m - 1, j, sti, x);
        if(l > i or r < i) return;
        int mid = l + (r - l) / 2;
        if(l <= i and i <= mid) this->update(2 * sti + 1, l, mid, i, j, x);
        else this->update(2 * sti + 2, mid + 1, r, i, j, x);
        for(int z = 0; z < this->m; z++)
            this->st[sti][z] = this->f(this->st[2 * sti + 1][z], this->st[2 * sti + 2][z]);
    }
    T queryx(int sti, int stl, int str, int l, int r, int node){
        if(str < l or stl > r) return this->neutral;
        if(stl >= l and str <= r) return this->st[node][sti];
        int mid = stl + (str - stl) / 2;
        return this->f(this->queryx(2 * sti + 1, stl, mid, l, r, node), this->queryx(2 * sti + 2, mid + 1, str, l, r, node));
    }
    T query(int sti, int stl, int str, int x, int y, int l, int r){
        if(str < x or stl > y) return this->neutral;
        if(stl >= x and str <= y) return this->queryx(0, 0, this->m - 1, l, r, sti);
        int mid = stl + (str - stl) / 2;
        return this->f(this->query(2 * sti + 1, stl, mid, x, y, l, r), this->query(2 * sti + 2, mid + 1, str, x, y, l, r));
    }
    public:
        SegmentTree2D(vector<vector<T>>& a, T neutral, T (*f)(T, T), T (*u)(T, T)): n(a.size()), m(a[0].size()){
            this->f = f, this->u = u, this->neutral = neutral;
            this->sizen = 2 * (int)pow(2, (int)(ceil(LOG2(this->n)))) - 1;
            this->sizem = 2 * (int)pow(2, (int)(ceil(LOG2(this->m)))) - 1;
            st = vector<vector<T>>(this->sizen, vector<T>(this->sizem, neutral));
            for(int i = 0; i < this->n; i++)
                this->update(0, 0, this->n - 1, i, a[i]);
        };
        SegmentTree2D(int n, int m, T neutral, T (*f)(T, T), T (*u)(T, T)): n(n), m(m){
            this->f = f, this->u = u, this->neutral = neutral;
            this->sizen = 2 * (int)pow(2, (int)(ceil(LOG2(n)))) - 1;
            this->sizem = 2 * (int)pow(2, (int)(ceil(LOG2(m)))) - 1;
            st = vector<vector<T>>(this->sizen, vector<T>(this->sizem, neutral));
        };
        void update(int i, int j, T x){
            return this->update(0, 0, this->n - 1, i, j, x);
        };
        void update(int i, vector<T>& a){
            return this->update(0, 0, this->n - 1, i, a);
        };
        T query(int x1, int y1, int x2, int y2){
            return this->query(0, 0, this->n - 1, x1, y1, x2, y2);
        };
};

int f(int a, int b){
    return (a + b);
}
int u(int a, int b){
    return b;
}

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    SegmentTree2D<int> aux(n, m, 0, f, u);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            scanf("%d", &a);
            aux.update(i, j, a);
        }
    }
    for(int z = 0; z < q; z++){
        int a, x, y, i, j, num;
        scanf("%d", &a);
        if(a == 1){
            scanf("%d %d %d %d", &x, &i, &y, &j);
            printf("[{%d, %d} <-> {%d, %d}] => %d\n", x, i, y, j, aux.query(x, y, i, j));
        } else {
            scanf("%d %d %d", &x, &i, &num);
            aux.update(x, i, num);
        }
    }
    return 0;
}