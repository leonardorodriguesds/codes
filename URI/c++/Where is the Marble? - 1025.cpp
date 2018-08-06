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
    int n, q, x = 0;
    while(true){
        int count = 0;
        x++;
        scanf("%d %d", &n, &q);
        if(n == 0 and q == 0)
            break;
        vi numbers(n);
        int num[10001];
        fill(num, -1);
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            numbers[i] = aux;
            if(!(~num[aux]))
                count++;
            num[aux] = 1;
        }
        sort(all(numbers));
        printf("CASE# %d:\n", x);
        for (int i = 0; i < q; i++){
            int aux;
            scanf("%d", &aux);
            int id = lIndex(aux, numbers);
            if(!(~num[aux]))
                printf("%d not found\n", aux);
            else
                printf("%d found at %d\n", aux, id + 1);
        }
    }
    return 0;
}