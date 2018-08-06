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
int solveIt(int, int, int, int);
ii search(int);
vvi result(2, vi());
vvi initial(2, vi());
int d[3][5];

int solveIt(int i, int j, int x, int y, vvi& e){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++)
            d[i][j] = INF;
    }
    priority_queue<tuple<ll, ii, vvi>, vector<tuple<ll, ii, vvi>>, greater<tuple<ll, ii, vvi>>> pq;
    d[i][j] = 0;
	pq.emplace(d[i][j], make_pair(i, j), e);
	ll dt, w;
    vvi aux;
	ii u, v;
    while(!pq.empty()){
		tie(dt, u, aux) = pq.top(); 
        pq.pop();
        if(u.first == x and u.second == y){
            e = aux;
            return dt;
        }
        if(u.first == 1 and d[u.first - 1][u.second] > (d[u.first][u.second] + initial[i][j] + initial[u.first - 1][u.second])){
            d[u.first - 1][u.second] = d[u.first][u.second] + initial[i][j] + initial[u.first - 1][u.second];
            vvi v(aux);
            swap(v[u.first - 1][u.second], v[u.first][u.second]);
            pq.emplace(d[u.first - 1][u.second], make_pair(u.first - 1, u.second), v);
        }
        if(u.first == 0 and d[u.first + 1][u.second] > (d[u.first][u.second] + initial[i][j] + initial[u.first + 1][u.second])){
            d[u.first + 1][u.second] = d[u.first][u.second] + initial[i][j] + initial[u.first + 1][u.second];
            vvi v(aux);
            swap(v[u.first + 1][u.second], v[u.first][u.second]);
            pq.emplace(d[u.first + 1][u.second], make_pair(u.first + 1, u.second), v);
        }
        if(u.second > 0 and d[u.first][u.second - 1] > d[u.first][u.second] + initial[i][j] + initial[u.first][u.second - 1]){
            d[u.first][u.second - 1] = d[u.first][u.second] + initial[i][j] + initial[u.first][u.second - 1];
            vvi v(aux);
            swap(v[u.first][u.second - 1], v[u.first][u.second]);
            pq.emplace(d[u.first][u.second - 1], make_pair(u.first, u.second - 1), v);
        }
        if(u.second < 3 and d[u.first][u.second + 1] > d[u.first][u.second] + initial[i][j] + initial[u.first][u.second + 1]){
            d[u.first][u.second + 1] = d[u.first][u.second] + initial[i][j] + initial[u.first][u.second + 1];
            vvi v(aux);
            swap(v[u.first][u.second + 1], v[u.first][u.second]);
            pq.emplace(d[u.first][u.second + 1], make_pair(u.first, u.second + 1), v);
        }
    }
    return 0;   
}

ii search(int elem){
    ii ans = make_pair(-1, -1);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            if(result[i][j] == elem and initial[i][j] != elem)
                return make_pair(i, j);
        }
    }
    return ans;
}

int main(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            int aux;
            scanf("%d", &aux);
            initial[i].push_back(aux);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            int aux;
            scanf("%d", &aux);
            result[i].push_back(aux);
        }
    }
    int ans = 0;
    bool reset = true;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            if(initial[i][j] != result[i][j]){
                ii u = search(initial[i][j]);
                ans += solveIt(i, j, u.first, u.second, initial);
            }
        }
        if(i and !equal(all(initial), result.begin()))
            i = -1;
    }
    printf("%d\n", ans);
}