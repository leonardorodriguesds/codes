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
    int x, y;
    scanf("%d %d", &y, &x);
    vs graph(x, "");
    for (int i = 0; i < x; i++)
        cin >> graph[i];
    int path[x][y];
    fill(path, -1);
    queue<ii> aux;
    aux.emplace(0, 0);
    path[0][0] = 1;
    int i, j, dx = 0, dy = 0;
    while(!(aux.empty())){
        tie(i, j) = aux.front();
        aux.pop();
        if(graph[i][j] == '*'){
            printf("*\n");
            return 0;
        }
        switch(graph[i][j]){
            case '>':
                dy = 1;
                dx = 0;
                break;
            case '<':
                dy = -1;
                dx = 0;
                break;
            case '^':
                dy = 0;
                dx = -1;
                break;
            case 'v':
                dy = 0;
                dx = 1;
                break;
        }
        if((j + dy) < 0 or (j + dy) > y or (i + dx) < 0 or (i + dx) > x) continue;
        else if(!(~path[i + dx][j + dy])){
            path[i + dx][j + dy] = 1;
            aux.emplace(i + dx, j + dy);
        }
    }
    printf("!\n");
    return 0;
}