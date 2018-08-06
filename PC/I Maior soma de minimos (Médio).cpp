#include <bits/stdc++.h>
using namespace std;
class  SegTree{
    vector<int> st;
    int size;

    int el_neutro = (1e9 + 7);

    int f(int a, int b){
        return min(a, b);
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
SegTree st(100001);
long long table[100001];

long long dp(int i){
    if(i + (x - 1) >= n)
        return 0;
    if(table[i] != -1)
        return table[i];
    long long ans = 0;
    if(i + (x - 1) < n)
        ans = st.query(i, i + (x - 1)) + dp(i + x);
    ans = max(ans, dp(i + 1));
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
    printf("%lld\n", dp(0));
    return 0;
}