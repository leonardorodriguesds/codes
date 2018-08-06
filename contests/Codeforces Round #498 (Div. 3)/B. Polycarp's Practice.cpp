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

class  SegTree{
    vector<int> st;
    int size;
    int el_neutro = -(1e9 + 7);
    int f(int a, int b){
        return max(a, b);
    }
    int query(int sti, int stl, int str, int l, int r){
        if(str < l || r < stl)
            return el_neutro;


        if(stl >= l and str <= r)
            return st[sti];

        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }
    void update(int sti, int stl, int str, int i, int amm){
        if(stl == i and str == i){
            st[sti] = amm;
            return;
        }

        if(stl > i or str < i)
            return;
        int mid = (stl + str)/2;
        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }
    public:
        SegTree(int n):  st(4*n,0){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
};

int n, x;
SegTree st(2001);
long long table[100001];

long long dp(int i, int k){
    if(i >= n and k < x or k > x)
        return -INF;
    if(k == x)
        return 0;
    if(table[i] != -1)
        return table[i];
    long long ans = 0;
    for(int j = i + 1; j < n; j++)
        ans = max(ans, st.query(i, j) + dp(j + 1, k + 1));
    ans = max(ans, st.query(i, i) + dp(i + 1, k + 1));
    table[i] = ans;
    return ans;
}

int main(){
    scanf("%d %d", &n, &x);
    memset(table, -1, sizeof(table));
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        st.update(i, aux);
    }    
    ll ans = dp(0, 0);
    printf("%lld\n", ans);
    return 0;
}