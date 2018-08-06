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
typedef set<int> si;
typedef map<string, int> msi;
vii nextCell(vvi&, int, int);
bool solveIt(vvi&, int, int);

vii nextCell(vvi& table, int i, int j){
    vii ans;
    if(j and table[i][j - 1] == 0)
        ans.emplace_back(i, j - 1);
    if(i and table[i - 1][j] == 0)
        ans.emplace_back(i - 1, j);
    if(j < 4 and table[i][j + 1] == 0)
        ans.emplace_back(i, j + 1);
    if(i < 4 and table[i + 1][j] == 0)
        ans.emplace_back(i + 1, j);
    return ans;
}

bool solveIt(vvi& table, int i, int j){
    if(i == 4 and j == 4)
        return true;
    if(table[i][j] == 0){
        table[i][j] = 2;
        vii next = nextCell(table, i, j);
        for(ii elem: next){
            if(solveIt(table, elem.first, elem.second))
                return true;
            table[elem.first][elem.second] = 0;
        }
        table[i][j] = 0;
        return false;
    }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        vvi table(5, vi(5, 0));
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                int aux;
                scanf("%d", &aux);
                table[i][j] = aux;
            }
        }
        printf("%s\n", (solveIt(table, 0, 0)? "COPS": "ROBBERS"));
    }
    return 0;
}