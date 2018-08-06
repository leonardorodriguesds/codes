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
    int h, l;
    scanf("%d %d", &h, &l);
    int table[h][l];
    fill(table, -1);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            getchar();
            char aux;
            scanf("%c", &aux);
            if(aux != 'C')
                table[i][j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < l; j++){
            if(!(~table[i][j])){
                int count = 0;
                queue<ii> aux;
                table[i][j] = 1;
                aux.emplace(i, j);
                int x, y;
                while(!(aux.empty())){
                    tie(x, y) = aux.front();
                    aux.pop();
                    count++;
                    if(x and !~table[x - 1][y]){
                        table[x - 1][y] = 1;
                        aux.emplace(x - 1, y);
                    }
                    if(x < h - 1 and !~table[x + 1][y]){
                        table[x + 1][y] = 1;
                        aux.emplace(x + 1, y);
                    }
                    if(y and !~table[x][y - 1]){
                        table[x][y - 1] = 1;
                        aux.emplace(x, y - 1);
                    }
                    if(y < l - 1 and !~table[x][y + 1]){
                        table[x][y + 1] = 1;
                        aux.emplace(x, y + 1);
                    }
                }
                ans = max(ans, count);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}