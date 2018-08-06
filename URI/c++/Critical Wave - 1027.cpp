#include <bits/stdc++.h>
using namespace std;
int num;
int table[10000][10001];
vector<pair<int, int>> points(0, pair<int, int>());
int dp(int i, int last, int z){
    if(i >= num)
        return 0;
    if(table[i][(last == -(1e9 + 7))? 0 : last + 1] != -1)
        return table[i][last];
    int ans = -(1e9 + 7);
    if(last == -(1e9 + 7) //Não existe um anterior
        or (
            (points[i].first > points[last].first) //X(i) > X(i - 1)  
            and (
                (z and points[last].second == points[i].second - (2 * (z))) //Y = a - 1 or a + 1
                or (!z 
                    and (
                        (points[last].second - points[i].second == 2) 
                        or (points[last].second - points[i].second == -2)
                    )
                )
            )
        )
    )
        ans = 1 + dp(i + 1, i, (last == -(1e9 + 7))? 0 : (points[last].second == points[i].second - (2 * (-1))? 1: -1));
    ans = max(ans, dp(i + 1, last, z));
    table[i][(last == -(1e9 + 7))? 0 : last + 1] = ans;
    return ans;
}

int main(){
    vector<int> ans;
    while(scanf("%d", &num)){
        points.resize(num);
        memset(table, -1, sizeof(table));
        for(int i = 0; i < num; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            points[i] = make_pair(x, y);
        }
        sort(points.begin(), points.end());
        ans.push_back(dp(0, -(1e9 + 7), 0));
    }
    for(auto u: ans)
        printf("%d\n", u);
    return 0;
}