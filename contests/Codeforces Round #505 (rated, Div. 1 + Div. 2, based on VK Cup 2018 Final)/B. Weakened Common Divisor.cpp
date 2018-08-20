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

vi aux;

void solveIt(int x){
    int i = 2, sq = sqrt(x) + 1;
    while(i <= sq and x > 1){
        if(x % i == 0){
            aux.push_back(i);
            while(x % i == 0) x /= i;
        }
        i++;
    }
    if(x != 1) aux.push_back(x);
}

int main(){
    int n;
    scanf("%d", &n);
    ii arr[n];
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        arr[i] = make_pair(a, b);
    }
    solveIt(arr[0].first);
    solveIt(arr[0].second);
    for(int d: aux){
        bool ans = true;
        for(int i = 1; i < n and ans; i++) 
            if(arr[i].first % d and arr[i].second % d){
                ans = false;
                break;
            }
        if(ans){
            printf("%d\n", d);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}