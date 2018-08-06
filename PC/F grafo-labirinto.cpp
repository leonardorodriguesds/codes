#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, h, q, x1, y1, x2, y2, ans;
    scanf("%d %d %d", &w, &h, &q);
    string line;
    vector<vector<bool>> graph(h, vector<bool>(w, false));
    for(int i = 0; i < h; i++){
        cin >> line;
        for(int j = 0; j < w; j++){
            if(line[j] == '#')
                graph[i][j] = 1;
        }
    }
    for(int i = 0; i < q; i++){
        vector<vector<bool>> visited(graph);
        ans = -1;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
        x1--; x2--; y1--; y2--;
        if(!visited[y1][x1]){
            queue<pair<pair<int, int>, int>> aux;
            aux.push(make_pair(make_pair(y1, x1), 0));
            visited[y1][x1] = true;
            while(aux.size()){
                auto current = aux.front();                    
                int l = current.first.first;
                int c = current.first.second;
                int size = current.second;
                aux.pop();
                if(c == x2 and l == y2){
                    ans = size;
                    break;
                }
                if((l + 1 < h) && (!visited[l + 1][c])){
                    aux.push(make_pair(make_pair(l + 1, c), size + 1));
                    visited[l + 1][c] = true;
                } 
                if((l - 1 >= 0) && (!visited[l - 1][c])){
                    aux.push(make_pair(make_pair(l - 1, c), size + 1));
                    visited[l - 1][c] = true;
                }
                if((c + 1 < w) && (!visited[l][c + 1])){
                    aux.push(make_pair(make_pair(l, c + 1), size + 1));
                    visited[l][c + 1] = true;
                }
                if((c - 1 >= 0) && (!visited[l][c - 1])){
                    aux.push(make_pair(make_pair(l, c - 1), size + 1));
                    visited[l][c - 1] = true;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}