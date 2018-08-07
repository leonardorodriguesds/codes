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

template<class T> class Node{
    Node<T>* left;
    Node<T>* right;
    public:
        T value;
        Node(int value): value(value){
            this->left = this->right = NULL;
        };
        ~Node(){
            if(this->left != NULL)
                delete this->left;
            if(this->right != NULL)
                delete this->right;
        };
        void insert(Node* x){
            if(x->value <= this->value)
                if(this->left == NULL)
                    this->left = x;
                else
                    this->left->insert(x);
            else
                if(this->right == NULL)
                    this->right = x;
                else
                    this->right->insert(x);
        };
        void insert(int l, int r, vi& num){
            if(l == r){
                this->value = num[l];
                return;
            }

            int middle = ((l + r) / 2);
            this->value = num[middle];
            if(this->left == NULL)
                this->left = new Node<T>(0);
            if(this->right == NULL)
                this->right = new Node<T>(0);
            this->left->insert(l, middle - 1, num);
            this->right->insert(middle + 1, r, num);
        };
        void preorder(){
            if(this->left != NULL)
                this->left->preorder();
            printf("%d ", this->value);
            if(this->right != NULL)
                this->right->preorder();
        };
    };

template<class T> class BST{
    Node<T>* root;
    public:
        BST(){
            this->root = NULL;
        };
        ~BST(){
            if(this->root != NULL)
                delete this->root;
        }
        void insert(T x){
            Node<T>* aux = new Node<T>(x);
            if(this->root == NULL)
                this->root = aux;
            else
                this->root->insert(aux);
        };
        void insert(int n, vi& num){
            if(this->root == NULL)
                this->root = new Node<T>(0);
            this->root->insert(0, n - 1, num);
        };
        void preorder(){
            if(this->root == NULL)
                printf("Doesn't exists a root\n");
            else this->root->preorder();
        };
};

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        if(n == 0)
            break;
        BST<int>* aux = new BST<int>();
        vi numbers;
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            numbers.push_back(a);
        }
        sort(all(numbers));
        for(int a: numbers)
            cout << a << " ";
        cout << endl;

        aux->insert(n, numbers);
        aux->preorder();
        delete aux;
    }
    return 0;
}