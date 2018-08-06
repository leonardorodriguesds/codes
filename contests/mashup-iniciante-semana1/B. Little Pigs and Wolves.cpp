#include <bits/stdc++.h>
using namespace std;
#define INF (1e9 + 7)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<string> table;
    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        table.push_back(line);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(table[i][j] == 'W'){
                if(i - 1 >= 0 and table[i - 1][j] == 'P'){
                    ans++;
                    continue;
                }
                if(i + 1 < n and table[i + 1][j] == 'P'){
                    ans++;
                    continue;
                }
                if(j - 1 >= 0 and table[i][j - 1] == 'P'){
                    ans++;
                    continue;
                }
                if(j + 1 < m and table[i][j + 1] == 'P'){
                    ans++;
                    continue;
                }
            }
    }
    printf("%d\n", ans);
    return 0;
}