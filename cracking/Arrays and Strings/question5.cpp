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
    string base, out;
    while(cin >> base >> out){
        int sz1 = sz(base), sz2 = sz(out), i = 0, j = 0;
        string s1 = base, s2 = out;
        if(sz2 < sz1)
            swap(s1, s2);
        bool flag = true, differ = false;
        while(i < sz1 and j < sz2){
            if(s1[i] != s2[j]){
                if(differ){
                    flag = false;
                    break;
                }
                differ = true;
                if(sz1 == sz2)
                    i++;
            } else
                i++;
            j++;
        }
        printf("%s\n", flag? "True" : "False");
    }
    return 0;
}