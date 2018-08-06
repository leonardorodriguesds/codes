#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
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
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int solveIt(int i, string lhs, string rhs, int lhend, int rhend){
    if(i >= lhend)
        return 0;
    int LCSuff[lhend + 1][rhend + 1];
    int result = 0;
    for (int i = 0; i <= lhend; i++){
        for (int j = 0; j <= rhend; j++){
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (lhs[i - 1] == rhs[j - 1]){
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else LCSuff[i][j] = 0;
        }
    }
    return result;
}

int main(){
    string lhs, rhs;
    while(getline(cin, lhs) and getline(cin, rhs))
        printf("%d\n", solveIt(0, lhs, rhs, sz(lhs), sz(rhs)));
    return 0;
}