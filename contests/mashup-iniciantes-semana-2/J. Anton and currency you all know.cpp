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
    string num, ans = "";
    cin >> num;
    for (int i = 0; i < (sz(num) - 1); i++){
        if(!((num[i] - '0') & 1)){
            string aux = num;
            if(num[i] < aux[sz(num) - 1]){
                swap(aux[i], aux[(sz(aux) - 1)]);
                ans = aux;
                break;
            }
        }
    }
    if(ans == ""){
        for (int i = (sz(num) - 1); i >= 0; i--){
            if(!((num[i] - '0') & 1)){
                string aux = num;
                if(num[i] > aux[sz(num) - 1]){
                    swap(aux[i], aux[(sz(aux) - 1)]);
                    ans = aux;
                    break;
                }
            }
        }
    }
    if(ans != "")
        cout << ans << endl;
    else
        printf("-1\n");
    return 0;
}