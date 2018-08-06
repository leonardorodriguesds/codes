#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define uIndex(x, v)     (upper_bound(all(v), x) - v.begin())
#define lIndex(x, v)     (lower_bound(all(v), x) - v.begin())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

int main(){
    int n;
    while(scanf("%d", &n)){
        deque<int> elem;
        priority_queue<int, vi> pq;
        bool stack = true, queue = true, priority_queue = true;
        for(int i = 0; i < n; i++){
            int a, x;
            scanf("%d %d", &a, &x);
            if(a == 1){
                elem.push_back(x);
                if(priority_queue) pq.push(x);
            } else{
                if(queue and !elem.empty()){
                    if(x != elem[0])
                        queue = false;
                    else
                        elem.pop_front();
                }
                if(stack and !elem.empty()){
                    if(x != elem[sz(elem) - 1])
                        stack = false;
                    else
                        elem.pop_back();
                }
                if(priority_queue and !pq.empty()){
                    if(x != pq.top())
                        priority_queue = false;
                    pq.pop();
                }
            }
            if(!stack and !queue and !priority_queue)
                break;
        }
        printf("%s\n", 
            ((queue and stack)
            or (stack and priority_queue)
            or (queue and priority_queue))? "not sure" : (stack)? "stack" 
            : (queue)? "queue": (priority_queue)? "priority queue" : "impossible");
    }
    return 0;
}