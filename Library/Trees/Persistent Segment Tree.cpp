/** Persistent Segment Tree
 * 
 * Problem : Given an array A[] and different point update operations.Considering 
 * each point operation to create a new version of the array. We need to answer 
 * the queries of type
 * Q v l r : output the sum of elements in range l to r just after the v-th update.
 * 
 * Time Complexity : The time complexity will be the same as the query and point 
 * update operation in the segment tree as we can consider the extra node creation 
 * step to be done in O(1). Hence, the overall Time Complexity per query for new 
 * version creation and range sum query will be O(log n).
 * 
 * https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/
 * 
 * TEST:
 * * a = 1 => Update idx;
 * * a = 2 => Query (l, r, version);
 * * a = 3 => Print version v;
 */

#include <bits/stdc++.h>
using namespace std;

template <class T> class PersistentSegmentTree{
    struct Node{
        T element;
        Node* left;
        Node* right;

        Node(){};
        Node(T element, Node* l, Node* r): element(element), left(l), right(r) {};
        ~Node(){
            if(this->left != NULL) delete this->left;
            if(this->right != NULL) delete this->right; 
        };
    };

    int nds, n;
    T neutral;
    vector<Node*> root;
    auto (*f)(T, T) -> T;
    auto (*u)(T, T) -> T;

    void build(Node* e, int l, int r, vector<T>& element){
        if(l == r){
            e->element = this->u(e->element, element[l]);
            return;
        }
        int mid = l + (r - l) / 2;
        e->left = new Node(this->neutral, NULL, NULL);
        e->right = new Node(this->neutral, NULL, NULL);
        this->build(e->left, l, mid, element);
        this->build(e->right, mid + 1, r, element);
        e->element = this->f(e->left->element, e->right->element);
    };

    T query(Node* e, int l, int r, int i, int j){
        if(i > r or j < l or l > r) return this->neutral;
        if(i <= l and r <= j) return e->element;
        int mid = l + (r - l) / 2;
        return this->f(this->query(e->left, l, mid, i, j), this->query(e->right, mid + 1, r, i, j));
    }

    void update(Node* prev, Node* e, int l, int r, int i, T x){
        if(i > r or i < l or l > r) return;
        if(l == r){
            e->element = this->u(e->element, x);
            return;
        }
        int mid = l + (r - l) / 2;
        if(i <= mid){
            e->right = prev->right;
            e->left = new Node(this->neutral, NULL, NULL);
            this->update(prev->left, e->left, l, mid, i, x);
        } else {
            e->left = prev->left;
            e->right = new Node(this->neutral, NULL, NULL);
            this->update(prev->right, e->right, mid + 1, r, i, x);
        }
        e->element = this->f(e->left->element, e->right->element);
    }
    public:
        PersistentSegmentTree(){};
        PersistentSegmentTree(vector<T>& elements, T neutral, T (*f)(T, T), T (*u)(T, T)){
            this->neutral = neutral, this->f = f, this->u = u;
            this->root.push_back(new Node(this->neutral, NULL, NULL));
            this->n = elements.size();
            this->nds = 0;
            this->build(this->root[0], 0, this->n - 1, elements);
        };
        PersistentSegmentTree(int n, T neutral, T (*f)(T, T), T (*u)(T, T)){
            vector<T> aux(n, neutral);
            this->neutral = neutral, this->f = f, this->u = u;
            this->root.push_back(new Node(this->neutral, NULL, NULL));
            this->n = n;
            this->nds = 0;
            this->build(this->root[0], 0, n - 1, this->n - 1, aux);
        };
        ~PersistentSegmentTree(){
            for(int i = 0; i <= this->nds; i++) delete this->root[i];
        };
        T query(int v, int l, int r){
            if(this->nds < v) return this->neutral;
            return this->query(this->root[v], 0, this->n - 1, l, r);
        };
        void update(int i, T x){
            this->root.push_back(new Node(this->neutral, NULL, NULL));
            this->nds++;
            this->update(this->root[this->nds - 1], this->root[this->nds], 0, this->n - 1, i, x);
        };
};

int main(){
    int n, q;
    while(scanf("%d %d", &n, &q) == 2){
        if(n == 0) break;
        vector<int> num(n, 0);
        for(int i = 0; i < n; i++) scanf("%d", &num[i]);
        auto f = [](int a, int b) -> int{ return (a + b); };
        auto u = [](int a, int b) -> int{ return b; };
        PersistentSegmentTree<int> aux(num, 0, f, u);
        for(int i = 0; i < q; i++){
            int t, a, b, v;
            scanf("%d %d", &t, &a);
            if(t == 1){
                scanf("%d", &b);
                aux.update(a, b);
            } else if(t == 2){
                scanf("%d %d", &b, &v);
                printf("%d\n", aux.query(v, a, b));
            }
        }
    }
    return 0;
}