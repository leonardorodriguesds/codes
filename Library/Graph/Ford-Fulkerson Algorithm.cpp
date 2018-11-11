/** Ford-Fulkerson Algorithm for Maximum Flow Problem
 * Given a graph which represents a flow network where every edge has a capacity. Also given 
 * two vertices source ‘s’ and sink ‘t’ in the graph, find the maximum possible flow from s 
 * to t with following constraints:
 * a) Flow on an edge doesn’t exceed the given capacity of the edge.
 * b) Incoming flow is equal to outgoing flow for every vertex except s and t.
 * 
 * ===========================================================================================
 * Ford-Fulkerson Algorithm 
 * The following is simple idea of Ford-Fulkerson algorithm:
 * 1) Start with initial flow as 0.
 * 2) While there is a augmenting path from source to sink. 
 *            Add this path-flow to flow.
 * 3) Return flow.
 * ===========================================================================================
 * 
 * https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
 */

#include <bits/stdc++.h>
using namespace std;
#define INF             0x3f3f3f3f
#define fill(t,v)       memset(t, v, sizeof(t))
typedef vector<vector<int>> vvi;
#define R 6
bool bfs(int, int, int[], int[R][R]);
int fordFulkerson(int, int, int[R][R]);

bool bfs(int s, int t, int parent[], int graph[R][R]){
    int visited[R];
    fill(visited, -1);
    queue<int> aux;
    aux.push(s);
    visited[s] = 1;
    while(!aux.empty()){
        int u = aux.front();
        aux.pop();
        for(int v = 0; v < R; v++)
            if(!~visited[v] and graph[u][v] > 0)
                parent[v] = u, visited[v] = 1, aux.push(v);
    }
    return (visited[t] == 1);
}

int fordFulkerson(int s, int t, int graph[R][R]){
    int rgraph[R][R];               //residualgraph
    for(int i = 0; i < R; i++)
        for(int j = 0; j < R; j++)
            rgraph[i][j] = graph[i][j];
    int ans = 0;                    //maxflow
    int parent[R];                  //current path
    while(bfs(s, t, parent, rgraph)){
        int pathflow = INF;
        for(int v = t; v != s; v = parent[v])
            pathflow = min(pathflow, rgraph[parent[v]][v]);
        for(int v = t; v != s; v = parent[v])
            rgraph[parent[v]][v] -= pathflow, rgraph[v][parent[v]] += pathflow;
        ans += pathflow;
    }
    return ans;
}

int main(){
    int graph[R][R] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      };
    printf("%d\n", fordFulkerson(0, 5, graph));
    return 0;
}