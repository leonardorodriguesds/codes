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
int table[8][8];
ii nextPos(ii&, ii&, bool);
vii checkIt(int, int, int);
int solveIt(int, int);

ii nextPos(ii& current, ii& dt, bool cont = true){
    int x, y, dx, dy;
    tie(x, y) = current;
    tie(dx, dy) = dt;
    while(((x + dx) >= 0 and (x + dx) <= 7) and ((y + dy) >= 0 and (y + dy) <= 7) 
    and (table[x + dx][y + dy] == 0 or table[x + dx][y + dy] == -1)){
        x += dx, y += dy;
        if(!cont or table[x][y] == -1) break;
    }
    return make_pair(x, y);
}

vii checkIt(int opt, int x, int y){
    vii ans;
    ii current = make_pair(x, y);
    ii dt;
    switch((char)opt){
        case 'Q':{
            dt = make_pair(1, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(0, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(0, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, 0);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, 0);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
        } break;
        case 'R':{
            dt = make_pair(0, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(0, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, 0);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, 0);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
        } break;
        case 'B':{
            dt = make_pair(1, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, -1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, 1);
            dt = nextPos(current, dt);
            if(dt != current)
                ans.push_back(dt);
        } break;
        case 'N':{
            dt = make_pair(2, 1);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(2, -1);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-2, 1);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-2, -1);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, 2);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(1, -2);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, 2);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
            dt = make_pair(-1, -2);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
        } break;
        default: {
            ans.emplace_back(x, y);
            dt = make_pair(1, 0);
            dt = nextPos(current, dt, false);
            if(dt != current)
                ans.push_back(dt);
        }
    }
    return ans;
}

int solveIt(int i, int j){
    if(table[i][j] == -1)
        return 0;
    int visited[8][8];
    fill(visited, -1);
    queue<array<int, 4>> aux;
    aux.push({0, table[i][j], i, j});
    visited[i][j] = 1;
    array<int, 4> ct;
    int x, y;
    while(!(aux.empty())){
        ct = aux.front();
        aux.pop();
        vii next = checkIt(ct[1], ct[2], ct[3]);
        for(auto n: next){
            tie(x, y) = n;
            if((!~table[x][y] and ct[1] != 'P') or (ct[1] == 'P' and 
                ((x + 1 <= 7 and y + 1 <= 7 and !~table[x + 1][y + 1])
                or (x - 1 >= 0 and y + 1 <= 7 and !~table[x - 1][y + 1])
                or (x + 1 <= 7 and y - 1 >= 0 and !~table[x + 1][y - 1])
                or (x - 1 >= 0 and y - 1 >= 0 and !~table[x - 1][y - 1])))){
                return ct[0];
            }
            else if(table[x][y] == 0 and !~visited[x][y]){
                visited[x][y] = 1;
                aux.push({ct[0] + 1, ct[1], x, y});
            }
        }
    }
    return INF;
}

int main(){
    int n;
    while(true){
        fill(table, 0);
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 0; i <= n; i++){
            string cmd;
            cin >> cmd;
            int x = 7 - (int)(cmd[sz(cmd) - 1] - '1'); 
            int y = (int)(cmd[sz(cmd) - 2] - 'a');
            table[x][y] = (i == n? -1 : (sz(cmd) > 2? cmd[0] : 'P'));
        }
        int ans = INF;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(table[i][j] and ~table[i][j])
                    ans = min(ans, solveIt(i, j));
            }
        }
        if(ans < INF)
            printf("%d\n", ans);
        else
            printf("INF\n");
    }
    return 0;
}