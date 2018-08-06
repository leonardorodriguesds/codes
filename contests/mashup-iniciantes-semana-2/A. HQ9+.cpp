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
    map<char, bool> instructions = {
        {'H', true},
        {'Q', true},
        {'9', true},
        {'+', false}
    };
    string cmd;
    cin >> cmd;
    for(int i = 0; i < sz(cmd); i++){
        if(instructions.count(cmd[i]) and instructions[cmd[i]]){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}