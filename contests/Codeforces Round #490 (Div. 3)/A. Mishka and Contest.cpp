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
    int n, k, left = 0, right = 0;
    scanf("%d %d", &n, &k);
    vi numbers;
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        numbers.push_back(aux);
        left = ((aux > k))? left: ((left == i)? (i + 1) : left);
    }
    for (int i = (n - 1); i >= 0; i--){
        int aux = right;
        right = ((numbers[i] > k))? right : ((right == (n - (i + 1)))? (n - i) : right);
        if(right == aux)
            break;
    }
    printf("%d\n", min(n, left + right));
    return 0;
}