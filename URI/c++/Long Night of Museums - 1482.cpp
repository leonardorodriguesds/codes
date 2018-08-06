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
int dp(int, int, int, vi&, vvi&);
int solveIt(vi&, vvi&);
int n;
const int boundtime = 7 * 60;
int table[21][(1 << 20)];

int dp(int i, int remainingtime, int bitmask, vi& times, vvi& travel){
    if(i >= n or remainingtime < 0 or times[i] > remainingtime)
        return 0;
    if(table[i][bitmask] != -1)
        return table[i][bitmask];
    int ans = 0;
    for (int j = 0; j < n; j++){
        if(j == i) continue;
        if(bitmask & (1 << j)) continue;
        if((remainingtime - (times[i] + travel[i][j])) >= times[j])
            ans = max(ans, dp(j, (remainingtime - (times[i] + travel[i][j])), (bitmask | (1 << j)), times, travel));
    }
    ans += 1;
    table[i][bitmask] = ans;
    return ans;
}

int solveIt(vi& times, vvi& travel){
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp(i, boundtime, (0 | (1 << i)), times, travel));
    return ans;
}

int main(){
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        fill(table, -1);
        vi times;
        vvi travel(n, vi());
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            times.push_back(aux);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int aux;
                scanf("%d", &aux);
                travel[i].push_back(aux);
            }
        }
        printf("%d\n", solveIt(times, travel));
    }
    return 0;
}