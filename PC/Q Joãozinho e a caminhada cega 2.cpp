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
int n, m, d, s;
vector<ii> graph[100001];
int aux[100001];
array<double, 2> table[100001];

array<double, 2> dp(int i){
    if(aux[i] != -1)
        return table[i];
    double odds = 0;
    double length = 0;
    for(auto elem: graph[i]){
        array<double, 2> next = dp(elem.first);
        odds += ((1/((double)graph[i].size())) * next[1]);
        length += (elem.second + next[0]);
    }
    array<double, 2> ans = {length, ((i == (s - 1))? 1 : odds)};
    table[i] = ans;
    aux[i] = 1;
    return ans;
}

int main(){
    fill(aux, -1);
    scanf("%d %d %d %d", &n, &m, &d, &s);
    for(int i = 0; i < m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a - 1].emplace_back(b - 1, w);
    }
    array<double, 2> ans = dp(d - 1);
    printf("%g\n%g\n", (ans[0] / (double)graph[d - 1].size()), ans[1]);
    return 0;
}