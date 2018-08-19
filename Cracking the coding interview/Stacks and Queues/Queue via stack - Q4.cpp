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

template <class T> class MyQueue{
    stack<T> *first, *second;
    void reverse();             //Complexy: O(N);
    public:
        MyQueue();              //Complexy: O(1);
        ~MyQueue();             //Complexy: O(1);
        void push(T);           //Complexy: O(1);
        T front();              //Complexy: O(N);
        void pop();             //Complexy: O(N);
};
template <class T> MyQueue<T>::MyQueue(){
    this->first = new stack<T>();
    this->second = new stack<T>();
}
template <class T> MyQueue<T>::~MyQueue(){
    delete this->first;
    delete this->second;
}
template <class T> void MyQueue<T>::push(T x){
    this->first->push(x);
}
template <class T> void MyQueue<T>::reverse(){
    if(!this->second->empty())
        return;
    while(!this->first->empty()){
        this->second->push(this->first->top());
        this->first->pop();
    }
}
template <class T> T MyQueue<T>::front(){
    this->reverse();
    T ans = this->second->top();
    return ans;
}
template <class T> void MyQueue<T>::pop(){
    this->reverse();
    this->second->pop();
}

int main(){
    int n;
    MyQueue<int>* aux = new MyQueue<int>();
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            aux->push(x);
        }
        for(int i = 0; i < n; i++){
            printf("%d ", aux->front());
            aux->pop();
        }
        printf("\n");
    }
    getchar();
    delete aux;
    return 0;
}