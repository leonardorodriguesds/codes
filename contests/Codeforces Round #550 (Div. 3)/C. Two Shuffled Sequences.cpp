#include <bits/stdc++.h>
using namespace std;
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;

int main(){
    int n;
    bool controll =  true, ans = true;
    set<int> increasing, decreasing;
    scanf("%d", &n);
    while (n--) {
        bool flag = true;
        int x;
        scanf("%d", &x);
        if (controll) {
            int aux = (int)increasing.size();
            increasing.insert(x);
            if (aux == (int) increasing.size()) flag = false;
        } 
        if(!controll || !flag) {
            flag = true;
            int aux = (int)decreasing.size();
            decreasing.insert(x);
            if (aux == (int) decreasing.size()) {
                aux = (int)increasing.size();
                increasing.insert(x);
                if (aux == (int) increasing.size()) {
                    ans = false;
                    break;
                }
            }
        }
        controll = !controll;
    }

    printf("%s\n", (ans)? "Yes" : "No");
    if (ans) {
        cout << increasing.size() << endl;
        for(int x: increasing) cout << x << " ";
        cout << endl;
        cout << decreasing.size() << endl;
        vi aux(all(decreasing));
        sort(aux.rbegin(), aux.rend());
        for(int x: aux) cout << x << " ";
        cout << endl;
    }
    return 0;
}