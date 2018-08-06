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

int main(){
    bool legs = false, elephant = false; int bear = 0;
    map<int, int> sticks;
    for(int i = 0; i < 6; i++){
        int aux;
        scanf("%d", &aux);
        sticks[aux]++;
    }
    for(ii set: sticks){
        if(set.second >= 4){
            legs = true;
            set.second -= 4;
            if(set.second == 2)
                elephant = true;
            else if(set.second)
                bear++;
        }
        else if(set.second >= 2)
            elephant = true;
        else if(set.second)
            bear++;
    }
    printf("%s\n", (legs and elephant and bear < 2)? "Elephant": ((legs and bear == 2) or (legs and sticks.size() == 3)? "Bear": "Alien"));
    return 0;
}