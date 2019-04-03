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
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf2(n, m);
        int* graph[m];
        for(int i = 0; i < m; i++){
            graph[i] = new int[6];
            for(int z = 0; z < 6; z++)
                graph[i][z] = n / 6;
        }
        map<string, int> aux = {{"XXL", 0}, {"XL", 1}, {"L", 2}, {"M", 3}, {"S", 4}, {"XS", 5}};
        for(int i = 0; i < m; i++){
            getchar();
            string x1, x2;
            cin >> x1;
            getchar();
            cin >> x2;
            
        }
    }
    return 0;
}