/** Wavelet Trees:
 * rank(i, j, k) => Retorna quantas vezes K aparece em [i, j];
 * quantile(i, j, k) => Retorna o K-ésimo elemento no intervalo [i, j];
 * 
 * Quando log(lb) > log(n) é necessário comprimir o input para caber em (4 * n);
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))

template <class T> class WaveletTree{
    int size;
    T lb, rb;
    vector<vector<int>> wt;
    vector<T> arr;

    void build(int sti, int stl, int str, T lo, T hi, T* a){
        if(lo == hi) return;
        T mid = lo + (hi - lo) / 2;
        vector<int>& aux = this->wt[sti];
        aux.reserve(str - stl + 2), aux.push_back(0);
        for(int i = stl; i <= str; i++) aux.push_back(aux.back() + (a[i] <= mid));
        int p = (int)(stable_partition((a + stl), (a + str + 1), [mid](T i)->int{ return (i <= mid); }) - a);
        this->build(2 * sti + 1, stl, p - 1, lo, mid, a);
        this->build(2 * sti + 2, p, str, mid + 1, hi, a);
    }

    int rank(int sti, T lo, T hi, T q, int i){
        if(lo == hi) return i;
        T mid = lo + (hi - lo) / 2, ri = this->wt[sti][i];
        if(q <= mid) return this->rank(2 * sti + 1, lo, mid, q, ri);
        return this->rank(2 * sti + 2, mid + 1, hi, q, i - ri);
    }

    T quantile(int sti, T lo, T hi, int i, int j, int k){
        if(lo == hi) return lo;
        T mid = lo + (hi - lo) / 2;
        int ri = this->wt[sti][i - 1], rj = this->wt[sti][j], c = rj - ri;
        if(k <= c) return this->quantile(2 * sti + 1, lo, mid, ri + 1, rj, k);
        else return this->quantile(2 * sti + 2, mid + 1, hi, i - ri, j - rj, k - c);
    }

    public:
        WaveletTree(){};
        WaveletTree(T* begin, T* end, T lb, T rb){
            this->lb = lb, this->rb = rb;
            this->size = (int)(end - begin);
            this->wt.resize(4 * n);
            this->arr = vector<T>(begin, end);
            this->build(0, 0, this->size - 1, lb, rb, begin);
        };
        WaveletTree(T* begin, T* end){
            this->lb = *begin, this->rb = *begin;
            this->size = (int)(end - begin);
            for(int i = 0; i < this->size; i++)
                this->lb = min(this->lb, *(begin + i)), this->rb = max(this->rb, *(begin + i));
            this->wt.resize(4 * n);
            this->arr = vector<T>(begin, end);
            this->build(0, 0, this->size - 1, lb, rb, &this->arr[0]);
            this->arr = vector<T>(begin, end);
        };
        int rank(int i, T q){
            return this->rank(0, this->lb, this->rb, q, i + 1);
        };
        int rank(int i, int j, T q){
            return this->rank(j, q) - this->rank(i - 1, q);
        };
        T quantile(int i, int j, int k){
            return this->quantile(0, this->lb, this->rb, i, j, k);
        };
};

int main(){
    int n, q;
    while(scanf("%d %d", &n, &q) == 2){
        if(n == 0 or q == 0) break;
        int num[n];
        for(int i = 0; i < n; i++) scanf("%d", &num[i]);
        WaveletTree<int> aux(num, num + n, 0, 5);
        for(int i = 0; i < q; i++){
            int t, a, b, w;
            scanf("%d %d %d %d", &t, &a, &b, &w);
            if(t == 1) printf("{%d, %d} => %d\n", aux.rank(a, w), aux.rank(b, w), aux.rank(a, b, w));
            else if(t == 2) printf("%d\n", aux.quantile(a, b, w));
        }
    }
    return 0;
}