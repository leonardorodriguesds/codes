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

class SqrtDecp{
    int n, sqrtX;
    unordered_map<int, int>* controll;
    int* data;
    public:
        SqrtDecp(int n);
        ~SqrtDecp();
        void insert(int x, int i);
        int query(int a, int b, int w);
        void update(int i, int a);
        void preProcessing();
};
SqrtDecp::SqrtDecp(int n){
    this->n = n;
    this->sqrtX = sqrt(n);
    this->data = new int[n];
    this->controll = new unordered_map<int, int>[this->sqrtX + 1];
}
SqrtDecp::~SqrtDecp(){
    delete [] this->data;
    delete [] this->controll;
}
void SqrtDecp::insert(int x, int i){
    this->data[i] = x;
}
void SqrtDecp::preProcessing(){
    int sqrtIdx = -1;
    for(int i = 0; i < this->n; i++){
        if(!(i % this->sqrtX))
            sqrtIdx++;
        this->controll[sqrtIdx][this->data[i]]++;
    }
}
void SqrtDecp::update(int i, int a){
    if(this->data[i] == a)
        return;
    int idx = (i / this->sqrtX);
    this->controll[idx][a]++;
    if(this->controll[idx][(this->data[i])] > 0)
        this->controll[idx][this->data[i]]--;
    this->data[i] = a;
}
int SqrtDecp::query(int l, int r, int w){
    int ans = 0;
    while((l < r) and ((l % this->sqrtX) != 0) and (l != 0)){
        if(this->data[l] != w)
            ans++;
        l++;
    }
    while(l + this->sqrtX - 1 <= r){
        ans += this->sqrtX;
        if(this->controll[(l / this->sqrtX)][w] > 0)
            ans -= this->controll[(l / this->sqrtX)][w];
        l += this->sqrtX;
    }
    while((l <= r)){
        if(this->data[l] != w)
            ans++;
        l++;
    }
    return ans;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    SqrtDecp* aux = new SqrtDecp(n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        aux->insert(a, i);
    }
    aux->preProcessing();
    for(int i = 0; i < q; i++){
        int a, x, y;
        scanf("%d %d %d", &a, &x, &y);
        if(a == 1){
            aux->update(x - 1, y);
        } else {
            int w;
            scanf("%d", &w);
            printf("%d\n", aux->query(x - 1, y - 1, w));
        }
    }
    delete aux;
    return 0;
}