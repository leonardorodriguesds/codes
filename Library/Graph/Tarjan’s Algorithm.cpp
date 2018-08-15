/** Tarjan's algorithm for SCCS
 * Tarjan's algorithm operates on the basis of low and discorevy time of each node,
 * looking for backedges across the graph;
 * 
 * Input:
 *  5 5
 *  {1 0}, {0 2}, {2 1}, {0 3}, {3 4};
 * Output:
 *  4
 *  3
 *  0 1 2
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define all(a)          a.begin(), a.end()
#define sz(v)           v.size()
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi TarjanHelper(int n, vvi&);
void DFSTarjan(vvi& graph, int u, int disc[], int low[], int stackH[], stack<int>& st, vvi& ans);

void DFSTarjan(vvi& graph, int u, int disc[], int low[], int stackH[], stack<int>& st, vvi& ans){
    static int time = 0;
    low[u] = disc[u] = ++time;
    st.push(u);                             //Push to track of active subtree
    stackH[u] = true;                       //Add the vertex to the active subtree
    for(int v: graph[u]){
        if(!~disc[v]){
            DFSTarjan(graph, v, disc, low, stackH, st, ans);
            low[u] = min(low[u], low[v]);   //Update disc time for backedges
        } else if(stackH[v] == true)        //Filter for crossedges
            low[u] = min(low[u], disc[v]);  //Update for backedges
    }
    if(low[u] == disc[u]){
        vi aux;
        while(st.top() != u){
            int x = st.top();
            st.pop();
            aux.push_back(x);
            stackH[x] = false;
        }
        aux.push_back(u);
        reverse(all(aux));
        stackH[u] = false;
        st.pop();
        ans.push_back(aux);
    }
}

vvi TarjanHelper(int n, vvi& graph){
    vvi ans;
    int disc[n], low[n], stackH[n];
    stack<int> st;
    for(int i = 0; i < n; i++) low[i] = disc[i] = -1, stackH[i] = false;
    for(int i = 0; i < n; i++)
        if(!~disc[i]) DFSTarjan(graph, i, disc, low, stackH, st, ans);
    return ans;
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        if(n == 0 and m == 0) break;
        vvi graph(n);
        for(int i = 0; i < m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }
        vvi ans = TarjanHelper(n, graph);
        for(vi e: ans){
            for(int u: e)
                printf("%d ", u);
            printf("\n");
        }
    }
    return 0;
}