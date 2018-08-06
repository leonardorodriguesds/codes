#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

bool is_lucky(int n){
    while (n != 0){
        if (n % 10 != 4 && n % 10 != 7){
            return false;
        }
        n /= 10;
    }
    return true;
}

bool calc(int n){
    if (is_lucky(n)){
        return true;
    }
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0 && (is_lucky(i) || is_lucky(n / i))){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    scanf("%d", &n);
    if (calc(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}