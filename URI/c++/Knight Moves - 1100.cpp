#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;
const int n = 8;
int table[n + 1][n + 1];

int main(){
    string start, finish;
    while(cin >> start >> finish){
        fill(table, -1);
        int x1, y1, x2, y2;
        x1 = start[0] - 'a';
        y1 = start[1] - '1';
        x2 = finish[0] - 'a';
        y2 = finish[1] - '1';
        queue<pair<int, ii>> aux;
        aux.emplace(0, make_pair(x1, y1));
        table[x1][y1] = 1;
        while(!(aux.empty())){
            pair<int, ii> v = aux.front();
            aux.pop();
            ii u = v.second;
            if(u.first == x2 and u.second == y2){
                printf("To get from %s to %s takes %d knight moves.\n", start.c_str(), finish.c_str(), v.first);
                break;
            }
            if(u.first - 2 >= 0 and u.second - 1 >= 0){
                table[u.first - 2][u.second - 1] = 1;
                aux.emplace(v.first + 1, make_pair(u.first - 2, u.second - 1));
            }
            if(u.first - 2 >= 0 and u.second + 1 < n){
                table[u.first - 2][u.second + 1] = 1;
                aux.emplace(v.first + 1, make_pair(u.first - 2, u.second + 1));
            }

            if(u.first + 2 < n and u.second - 1 >= 0){
                table[u.first + 2][u.second - 1] = 1;
                aux.emplace(v.first + 1, make_pair(u.first + 2, u.second - 1));
            }
            if(u.first + 2 < n and u.second + 1 < n){
                table[u.first + 2][u.second + 1] = 1;
                aux.emplace(v.first + 1, make_pair(u.first + 2, u.second + 1));
            }
            if(u.first - 1 >= 0 and u.second - 2 >= 0){
                table[u.first - 1][u.second - 2] = 1;
                aux.emplace(v.first + 1, make_pair(u.first - 1, u.second - 2));
            }
            if(u.first + 1 < n and u.second - 2 >= 0){
                table[u.first + 1][u.second - 2] = 1;
                aux.emplace(v.first + 1, make_pair(u.first + 1, u.second - 2));
            }
            if(u.first - 1 >= 0 and u.second + 2 < n){
                table[u.first - 1][u.second + 2] = 1;
                aux.emplace(v.first + 1, make_pair(u.first - 1, u.second + 2));
            }
            if(u.first + 1 < n and u.second + 2 < n){
                table[u.first + 1][u.second + 2] = 1;
                aux.emplace(v.first + 1, make_pair(u.first + 1, u.second + 2));
            }
        }
    }
    return 0;
}