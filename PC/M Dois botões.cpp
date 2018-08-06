#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int visited[2 * 100005];
    memset(visited, -1, sizeof(visited));
    queue<pair<int, int>> aux;
    aux.push(make_pair(n, 0));
    visited[n] = 1;
    int ans = -1;
    while(!aux.empty()){
        auto elem = aux.front();
        aux.pop();
        if(elem.first == x){
            ans = elem.second;
            break;
        }
        if(elem.first * 2 < 2 * 100005 and visited[elem.first * 2] == -1){
            visited[elem.first * 2] = 1;
            aux.push(make_pair(elem.first * 2, elem.second + 1));
        }
        if(elem.first >= 3 and visited[elem.first - 3] == -1){
            visited[elem.first - 3] = 1;
            aux.push(make_pair(elem.first - 3, elem.second + 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}