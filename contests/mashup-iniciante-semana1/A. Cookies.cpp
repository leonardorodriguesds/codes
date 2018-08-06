#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mii;
int n;
mii cookies;

int main(){
    int amount = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        amount += aux;
        cookies[aux]++;
    }
    int ans = 0;
    for(auto bag: cookies){
        if((((amount - bag.first) % 2) == 0))
            ans += bag.second;
    }
    printf("%d\n", ans);
    return 0;
}