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
    int r, c, row = 0, colunm = 0, rows = 0, colunms = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++){
        string line;
        cin >> line;
        for (int j = 0; j < sz(line); j++){
            if(line[j] == 'S'){
                if(!(rows & (1 << i)))
                    row++;
                if(!(colunms & (1 << j)))
                    colunm++;
                rows |= (1 << i);
                colunms |= (1 << j);
            }
        }
    }
    printf("%d\n", ((r * c) - (row * colunm)));
    return 0;
}