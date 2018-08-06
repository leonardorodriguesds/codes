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
    int n;
    scanf("%d", &n);
    getchar();
    while(n--){
        string line;
        getline(cin, line);
        stringstream ss(line);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> ans(begin, end);
        vector<ii> vstrings;
        int i = 0;
        for(string e: ans)
            vstrings.emplace_back(sz(e), i++);
        sort(all(vstrings), solveIt);
        for(ii e: vstrings)
            printf("%s ", ans[e.second].c_str());
        printf("\n");
    }
    return 0;
}