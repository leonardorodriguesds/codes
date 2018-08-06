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

bool solveIt(ii f, ii s){
    return (f.first > s.first)? true : (f.second < s.second);
}

int main(){
    string line;
    while(true){
        if(cin.eof()) 
            break;
        cin >> line;
        map<int, int> count;
        for (int i = 0; i < sz(line); i++){
            if(line[i] == '\n' or line[i] == '\r') continue;
            count[line[i]]++;
        }
        vii ans;
        for(auto e: count)
            ans.emplace_back(e.second, e.first);
        sort(all(ans), solveIt);
        reverse(all(ans));
        for(ii e: ans)
            printf("%d %d\n", e.second, e.first);
        printf("\n");
        getchar();
    }
    return 0;
}