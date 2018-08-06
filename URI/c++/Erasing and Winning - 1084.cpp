#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
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
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int n, d;
    while(true){
        scanf("%d %d", &n, &d);
        if(n == 0 and d == 0)
            break;
        string num, ans = "";
        cin >> num;
        int sz = sz(num);
        stack<char> aux;
        for (int i = 0; i < sz; i++){
            while((!aux.empty()) and (aux.top() < num[i]) and (aux.size() + sz - (i + 1)) >= (n - d))
                aux.pop();
            if((aux.size() < (n - d)))
                aux.push(num[i]);            
        }
        while(!aux.empty()){
            ans += aux.top();
            aux.pop();
        }
        reverse(all(ans));
        printf("%s\n", ans.c_str());
    }
    return 0;
}