#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)    (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)    (lower_bound(all(v), x) - v.begin())
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
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

class WaveletTree{
    int size;
    int lb, rb;
    vector<vector<int>> wt;

    void build(int sti, int stl, int str, int lo, int hi, int* a){
        if(lo == hi) return;
        int mid = lo + (hi - lo) / 2;
        vector<int>& aux = this->wt[sti];
        aux.reserve(str - stl + 2), aux.push_back(0);
        for(int i = stl; i <= str; i++) aux.push_back(aux.back() + (a[i] <= mid));
        int p = (int)(stable_partition((a + stl), (a + str + 1), [mid](int i)->int{ return (i <= mid); }) - a);
        this->build(2 * sti + 1, stl, p - 1, lo, mid, a);
        this->build(2 * sti + 2, p, str, mid + 1, hi, a);
    }

    int quantile(int sti, int lo, int hi, int i, int j, int k){
        if(lo == hi) return lo;
        int mid = lo + (hi - lo) / 2;
        int ri = this->wt[sti][i - 1], rj = this->wt[sti][j], c = rj - ri;
        if(k <= c) return this->quantile(2 * sti + 1, lo, mid, ri + 1, rj, k);
        else return this->quantile(2 * sti + 2, mid + 1, hi, i - ri, j - rj, k - c);
    }

    public:
        WaveletTree(){};
        WaveletTree(int n, int* begin, int* end, int lb, int rb){
            this->lb = lb, this->rb = rb;
            this->size = n;
            this->wt.resize(4 * n);
            this->build(0, 0, n - 1, lb, rb, begin);
        };
        int quantile(int i, int j, int k){
            return this->quantile(0, this->lb, this->rb, i, j, k);
        };
};

/** Best solution => 0.34ms
 */
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int num[n], arr[n], controll[n];
    vii in;
    in.reserve(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        in.emplace_back(num[i], i);
    }
    sort(all(in));
    for(int i = 0; i < n; i++) in[i].first = i;
    sort(all(in), [](ii& a, ii& b){ return (a.second < b.second); });
    for(int i = 0; i < n; i++) arr[i] = in[i].first, controll[arr[i]] = num[in[i].second];
    WaveletTree aux(n, arr, arr + n, 0, n - 1);
    for(int z = 0; z < m; z++){
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", controll[aux.quantile(i, j, k)]);
    }
    return 0;
} 

/** 2 solution => 0.65ms
 */
/* int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int num[n], controll[n];
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    {
        map<int, int> aux;
        for(int i = 0; i < n; i++) aux[num[i]] = 0;
        int idx = 0;
        for(auto &x: aux) x.second = idx++;
        for(int i = 0; i < n; i++) controll[aux[num[i]]] = num[i], num[i] = aux[num[i]];
    }
    WaveletTree aux(n, num, num + n, 0, n - 1);
    for(int z = 0; z < m; z++){
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", controll[aux.quantile(i, j, k)]);
    }
    return 0;
} */