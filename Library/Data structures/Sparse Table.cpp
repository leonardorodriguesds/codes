#include <bits/stdc++.h>
using namespace std;
#define INF             0x3f3f3f3f
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))

template <class I, class T> class SparseTable{
    int size;
    I neutral;
    auto (*f)(T&, T&) -> T;
    vector<vector<T>> arr;
    
    public:
        SparseTable(I* begin, I* end, I neutral, T (*f)(T&, T&)){
            this->f = f, this->neutral = neutral;
            this->size = (int)(end - begin);
            this->arr.assign(this->size + 1, vector<T>(((int)LOG2(this->size) + 1), this->neutral));
            for(int i = 0; i < this->size; i++) this->arr[i][0] = (T)begin[i];
            for(int j = 1; (j << j) <= this->size; j++)
                for(int i = 0; (i + (1 << j) - 1) < this->size; i++)
                    this->arr[i][j] = this->f(this->arr[i][j - 1], this->arr[i + (1 << (j - 1))][j - 1]);
        };
        T query(int i, int j){
            int k = (int)LOG2(j - i + 1);
            return this->f(this->arr[i][k], this->arr[j - (1 << k) + 1][k]);
        };
};

int main(){
    int n, q;
    while(scanf("%d %d", &n, &q) == 2){
        if(n == 0) break;
        int arr[n];
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        SparseTable<int, int> aux(arr, arr + n, INF, [](int& a, int& b) -> int{ return min(a, b); });
        for(int i = 0; i < q; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", aux.query(a, b));
        }
    }
    return 0;
}