#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
int n;
vi numbers;

int maximumDifferenceSum(){
    int dp[n][2];
    for (int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = 0;
 
    for (int i=0; i<(n-1); i++){
        dp[i + 1][0] = max(dp[i][0],
                          dp[i][1] + abs(1-numbers[i]));
        dp[i + 1][1] = max(dp[i][0] + abs(numbers[i+1] - 1),
                     dp[i][1] + abs(numbers[i+1] - numbers[i]));
    } 
    return max(dp[n-1][0], dp[n-1][1]);
}

int main(){
    int t, x;
    scanf("%d", &t);
    x = t;
    while(t--){
        numbers.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            numbers.push_back(aux);
        }
        printf("case %d: %d\n", (x - t), maximumDifferenceSum());
    }
    return 0;
}