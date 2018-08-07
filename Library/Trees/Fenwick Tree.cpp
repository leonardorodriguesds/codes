#include <bits/stdc++.h>
using namespace std;

/** Fenwick Tree, by Leonardo Rodrigues.
 * Query: O(log N);
 * Update: O(log N);
 * 
 * neutral = Elemento neutro dentro da estrutura;
 * f = Função de acumulação de valores dentre intervalos;
 * u = Função de atualização de valores dentre os intervalos.
 * 
 * Utilização:
 * * FenwickTree<T> aux(N, neutral, T (T a, T b){ return a + b; }, T (T a, T b){ return a + b; });
*/
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

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    FenwickTree<int> aux(n, 0, [](int a, int b)->int{ return (a + b); }, [](int a, int b)->int{ return (a + b); });
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        aux.update(i, a);
    }
    for(int i = 0; i < q; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) printf("{%d, %d} => %d\n", b, c, aux.query(b, c));
        else aux.update(b, c);
    }
    return 0;
}