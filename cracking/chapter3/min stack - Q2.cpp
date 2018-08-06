#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define SINF            (1e18)
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
typedef vector<vii> vvii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

class StackMin{
    int n, idx;
    vii st;
    public:
        StackMin(int);
        void push(int);     //Complexy: O(1);
        void pop();         //Complexy: O(1);
        int top();          //Complexy: O(1);
        int min();          //Complexy: O(1);
        bool empty();       //Complexy: O(1);
        bool full();        //Complexy: O(1);
};
StackMin::StackMin(int n){
    this->st.assign(n, ii(0, 0));
    this->n = n, this->idx = 0;
}
bool StackMin::empty(){
    return (this->idx == 0);
}
bool StackMin::full(){
    return (this->idx == this->n);
}
void StackMin::push(int x){
    if(!this->full())
        this->st[this->idx++] = make_pair(x, 
            (!this->empty())? (x <= this->min()? x : this->min()) : x);
    else throw runtime_error("There is no available space in stack!");
}
int StackMin::top(){
    if(!this->empty())
        return this->st[this->idx - 1].first;
    else throw runtime_error("There is no a available item in stack!");
}
void StackMin::pop(){
    if(!this->empty())
        this->idx--;
    else throw runtime_error("There is no a available item in stack!");
}
int StackMin::min(){
    if(!this->empty())
        return this->st[this->idx - 1].second;
    else throw runtime_error("There is no a available item in stack!");
}

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        StackMin aux(n);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            aux.push(x);
        }
        for(int i = 0; i < n; i++){
            printf("{min: %d} <=> {top: %d}\n", aux.min(), aux.top());
            aux.pop();
        }
    }
    return 0;
}