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

class SparseT{
    int n;
    int lgN;
    int* data;
    int** table;
    auto (*f)(int a, int b)->int;

    void buildsparsetable();
    public:
        SparseT(int n);
        ~SparseT();
        void buildTable(int (*f)(int, int));
        int query(int i, int j);
};
SparseT::SparseT(int n){
    this->n = n;
    this->lgN = (int)LOG2(n);
    this->data = new int[n];
    this->table = new int*[n];
    for(int i = 0; i < n; i++)
        this->table[i] = new int[this->lgN + 1];
}
SparseT::~SparseT(){
    delete [] this->data;
    for(int i = 0; i < n; i++)
        delete[] this->table[i];
    delete [] this->table;
}
void SparseT::buildTable(int (*f)(int, int)){
    for(int i = 0; i < this->n; i++)
        scanf("%d", &this->data[i]);
    this->f = f;
    this->buildsparsetable();
}
void SparseT::buildsparsetable(){
    for(int i = 0; i < this->n; i++)
        this->table[i][0] = this->data[i];
    for(int j = 1; (1 << j) <= this->n; j++)
        for(int i = 0; (i + (1 << j) - 1) < n; i++)
            this->table[i][j] = this->f(this->table[i][j - 1], 
                                this->table[i + (1 << (j - 1))][j - 1]);
}
int SparseT::query(int l, int r){
    int j = (int)LOG2(r - l + 1);
    return this->f(this->table[l][j], this->table[r - (1 << j) + 1][j]);
}

int func(int a, int b){
    return min(a, b);
}

int main(){
    int n, q;
    scanf("%d", &n);
    SparseT* aux = new SparseT(n);
    aux->buildTable(func);
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", aux->query(a, b));
    }
    delete aux;
    return 0;
}