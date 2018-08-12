#include <bits/stdc++.h>
using namespace std;
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))

template <class T> class SparseTable{
    int size;
    auto (*f)(T&, T&) -> T;
    vector<vector<T>> arr;
    
    public:
        SparseTable(int* begin, int* end){
            this->size = (int)(end - begin);
            this->arr.assign(this->size, vector<T>((int)LOG2(this->size) + 1));
            for(int i = 0; i < this->size; i++) this->arr[i][0] = 0;
            for(int j = 1; (j << j) < this->size; j++)
                for(int i = 0; i + (1 << j) < this->size; i++)
                    this->arr[i][j] = this->f(this->[i][j - 1], this->[i + (1 << (j - 1))][j - 1]);
        };
        T query(int i, int j){
            int k = (int)LOG2(j - i + 1);
            return this->f(this->arr[i][k], this->arr[j - (1 << k) + 1][k]);
        };
};

int main(){
    
    return 0;
}