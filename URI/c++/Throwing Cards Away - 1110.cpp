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

int main(){
    int n;
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        bool type = false;
        vi ans;
        queue<int> aux;
        for(int i = 1; i <= n; i++){
            if(i & 1)
                ans.push_back(i);
            else
                aux.push(i);
            type  = !type;
        }
        while((aux.size() > 1)){
            if(type)
                aux.push(aux.front());
            else
                ans.push_back(aux.front());
            aux.pop();
            type = !type;
        }
        printf("Discarded cards: ");
        for(int i = 0; i < n - 1; i++)
            printf("%d%s", ans[i], ((i != n - 2)? ", " : ""));
        printf("\nRemaining card: %d\n", aux.front());
    }
    return 0;
}