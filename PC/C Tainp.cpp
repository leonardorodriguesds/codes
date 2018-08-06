#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);
    int visited[505][505];
    string line;
    for(int i = 0; i < n; i++){
        cin >> line;
        for(int j = 0; j < m; j++){
            if(line[j] == '#')
                visited[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(not visited[i][j]){
                queue<pair<int, int>> aux;
                aux.push(make_pair(i, j));
                visited[i][j] = 1;
                ans++;
                while(aux.size()){
                    auto current = aux.front();                    
                    int l = current.first;
                    int c = current.second;
                    aux.pop();
                    if((l + 1 < n) && (not visited[l + 1][c])){
                        aux.push(make_pair(l + 1, c));
                        visited[l + 1][c] = 1;
                    } 
                    if((l - 1 >= 0) && (not visited[l - 1][c])){
                        aux.push(make_pair(l - 1, c));
                        visited[l - 1][c] = 1;
                    }
                    if((c + 1 < m) && (not visited[l][c + 1])){
                        aux.push(make_pair(l, c + 1));
                        visited[l][c + 1] = 1;
                    }
                    if((c - 1 >= 0) && (not visited[l][c - 1])){
                        aux.push(make_pair(l, c - 1));
                        visited[l][c - 1] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}