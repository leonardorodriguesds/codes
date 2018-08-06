#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int root, int total, vector<vector<int>>& graph){
    pair<int, int> current;
    vector<int> ans(total, -1);
    vector<bool> visited(total, false);
    queue<pair<int, int>> aux;
    visited[root] = true;
    aux.push(make_pair(root, 0));
    while(!(aux.empty())){
        current = aux.front();
        aux.pop();
        ans[current.first] = current.second;
        for(auto vertex: graph[current.first]){
            if(!visited[vertex]){
                aux.push(make_pair(vertex, current.second + 1));
                visited[vertex] = true;
            }
        }
    }
    return ans;
}

int main(){
    int n, m, q, k, l, r, x, result;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        graph[l - 1].push_back(r - 1);
        graph[r - 1].push_back(l - 1);
    }
    vector<int> distance = bfs(k - 1, n, graph);
    for(int i = 0; i < q; i++){
        scanf("%d", &x);
        if(distance[--x] >= 0)
            printf("%d\n", distance[x]);
        else
            printf("infinito\n");
    }
    return 0;
}