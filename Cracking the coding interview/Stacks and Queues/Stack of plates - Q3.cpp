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

class SetofStacks{
    int maxsz, idx;
    vector<stack<int>> st;
    public:
        SetofStacks(int);
        void push(int);         //complexity: O(1);
        void push(int, int);    //complexity: O(1);
        void pop();             //complexity: O(1);
        void pop(int);          //complexity: O(1);
        int top();              //complexity: O(1);
        int top(int);           //complexity: O(1);
};
SetofStacks::SetofStacks(int maxsz){
    this->maxsz = maxsz;
    this->idx = -1;
}
void SetofStacks::push(int x){
    if(!~this->idx or this->st[this->idx].size() >= this->maxsz){
        st.push_back(stack<int>());
        this->idx++;
    }
    this->st[this->idx].push(x);
}
void SetofStacks::push(int i, int x){
    if(this->idx >= i and this->st[i].size() < this->maxsz){
        this->st[i].push(x);
    } else throw runtime_error("There is stack id or no space available in stack id!");
}
int SetofStacks::top(){
    if(!~this->idx)
        throw runtime_error("There is no an stack available!");
    return this->st[this->idx].top();
}
int SetofStacks::top(int i){
    if(!~this->idx or this->idx < i)
        throw runtime_error("There is no an stack available or no stack id available!");
    return this->st[i].top();
}
void SetofStacks::pop(){
    if(!~this->idx)
        throw runtime_error("There is no an stack available!");
    if(!this->st[this->idx].empty())
        this->st[this->idx].pop();
    if(this->st[this->idx].empty()){
        this->st.erase(this->st.begin() + this->idx);
        this->idx--;
    }
}
void SetofStacks::pop(int i){
    if(!~this->idx or this->idx < i)
        throw runtime_error("There is no an stack available or no stack id available!");
    if(!this->st[i].empty())
        this->st[i].pop();
    if(this->st[i].empty()){
        this->st.erase(this->st.begin() + i);
        this->idx--;
    }
}

int main(){
    int a, maxsz;
    scanf("%d", &maxsz);
    SetofStacks aux(maxsz);
    while(scanf("%d", &a) == 1){
        if(a == 0)
            break;
        int b, c, d;
        switch(a){
            case 1:
                scanf("%d", &b);
                aux.push(b);
                break;
            case 2:
                scanf("%d %d", &b, &c);
                aux.push(b, c);
                break;
            case 3:
                printf("top: %d\n", aux.top());
                aux.pop();
                break;
            case 4:
                scanf("%d", &b);
                printf("top: %d\n", aux.top(b));
                aux.pop(b);
        }
    }
    return 0;
}