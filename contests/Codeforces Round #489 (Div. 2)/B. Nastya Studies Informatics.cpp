#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

long long C(int p, int n){
    int num = n;
	long long ans = 1;
    for (int i = 0; i < (n - p); i++){
        ans *= num--;
    }
    long long fp = 1;
    for (int i = p; i > 0; i--){
        fp *= i;
    }
    return (ans == 1)? ans : (ans / fp);
}

int main(){
    int l, r, x, y, count = 0;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    for (int i = l; i <= r; i++){
        if(!(i % x) and !(y % i))
            count++;
    }
    printf("%lld\n", C(2, count));
    return 0;
}