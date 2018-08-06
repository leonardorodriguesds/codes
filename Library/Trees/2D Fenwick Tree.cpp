#include <bits/stdc++.h>
using namespace std;

/**
 * Query(x1,y1,x2,y2) = sum(x2, y2)- sum(x2, y1-1) -
                        sum(x1-1, y2) + sum(x1-1, y1-1);
 * Constraints -> x1<=x2 and y1<=y2
 * 
    /\
 y  |
    | ________  _______
    ||       *4|      *5
    ||        ||       |
    ||        ||       |
    ||        ||       |
    ||________|*3______|
    ||       *1       *2
    ||        |        |
    ||________|________|_________
   (0, 0)                     x-->
   *1 => área de (0, 0) <-> (x1 -1, y1 -1),
   *2 => área de (0, 0) <-> (x1 - 1, y2),
   *3 => área de (0, 0) <-> (x1, y1),
   *4 => área de (0, 0) <-> (x2, y1 - 1);
   *5 => área de (0, 0) <-> (x2, y2),

   **ÁREA de (3) <-> (5): *5 - *4 - *2 + *1 => Área de (x1, y1) <-> (x2, y2);
 */
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
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    FenwickTree2D<int> aux(n, m, 0, f);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a;
            scanf("%d", &a);
            aux.update(i, j, a);
        }
    }
    for(int i = 0; i < q; i++){
        int a, b, c, x, y;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 1) {
            scanf("%d", &x);
            aux.update(b, c, x);
        } else if(a == 2){
            scanf("%d %d", &x, &y);
            printf("{(%d, %d) <-> (%d, %d)} => %d\n", b, c, x, y, aux.query(b, c, x, y));
        } else if(a == 3)
            printf("{%d, %d} => %d\n", b, c, aux.query(b, c));
    }
    return 0;
}