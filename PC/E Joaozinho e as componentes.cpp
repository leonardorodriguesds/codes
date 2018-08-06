#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    vector<vector<int>> graph(n);
    vector<bool> mark(n, false);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &l, &r);
        graph[l - 1].push_back(r - 1);
        graph[r - 1].push_back(l - 1);
    }
    for(int i = 0; i < n; i++){
        if(mark[i] == false){
            vector<int> ans;
            stack<int> aux;
            aux.push(i);
            int current;
            mark[i] = true;
            while(!aux.empty()){
                current = aux.top();
                aux.pop();
                ans.push_back(current + 1);
                for(auto vertex: graph[current]){
                    if(mark[vertex] == false){
                        aux.push(vertex);
                        mark[vertex] = true;
                    }
                }
            }
            sort(ans.begin(), ans.end());
            for(auto num: ans)
                printf("%d ", num);
            printf("\n");
        }
    }
    return 0;
}