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
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
long long fs[5001];

long long sum(int l, int r) {
    if (l == r) return 0;
    else if (l == 0) return fs[r - 1];
    else return fs[r - 1] - fs[l - 1];
}

int main(){
    int n;
    cin >> n;
    fill(fs, 0);
    for(int i = 0; i < n; i++){
        long long a;
        scanf("%lld", &a);
        fs[i] = a;
        if (i) fs[i] += fs[i - 1];
    }

    array<int, 3> delim = { 0, 0, 0 };
    long long ans = -INFLL;
    for(int i = 0; i <= n; i++){
        long long aux = -sum(0, i);
        int s0 = 0, s1 = i, s2 = i;
        for(int j = 0; j <= i; j++){
            if (aux < (sum(0, j) - sum(j , i)))
                aux = (sum(0, j) - sum(j , i)), s0 = j;
        }

        long long aux2 = -sum(i, n);
        for(int j = i; j <= n; j++){
            if (aux2 < (sum(i , j) - sum(j, n)))
                aux2 = (sum(i , j) - sum(j, n)), s2 = j;
        }

        if (ans < (aux + aux2))
            ans = (aux + aux2), delim[0] = s0, delim[1] = s1, delim[2] = s2;
    }
    
    cout << delim[0] << " " << delim[1] << " " << delim[2] << endl;
    return 0;
}