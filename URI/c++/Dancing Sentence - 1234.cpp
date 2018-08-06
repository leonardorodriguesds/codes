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
    string str;
    while(getline(cin, str)){
        bool controll = true;
        for (int i = 0; i < sz(str); i++){
            if(str[i] >= 'A' and str[i] <= 'Z' or str[i] >= 'a' and str[i] <= 'z'){
                str[i] = (controll)? (char)(str[i] - ((str[i] >= 97)? 32 : 0)): str[i] + ((str[i] <= 90)? 32 : 0);
                controll = !controll;
            }
        }
        printf("%s\n", str.c_str());
    }
    return 0;
}