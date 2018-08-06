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

typedef struct s_node{
    int element;
    struct s_node* left;
    struct s_node* right;
} node;

class BSTree{
    private:
        node* root;
        void destroy_tree(node *leaf);
        void insert(int element, node *leaf);
        void inorder_print(node *leaf);
    public:
        BSTree();
        ~BSTree();
        void insert(int element);
        void destroy_tree();
        void inorder_print();
};
BSTree::BSTree(){
    root = NULL;
}
BSTree::~BSTree(){
    destroy_tree();
}
void BSTree::destroy_tree(){
    destroy_tree(root);
}
void BSTree::destroy_tree(node* leaf){
    if(leaf != NULL){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
void BSTree::insert(int element, node *leaf){
    if(element < leaf->element){
        if(leaf->left != NULL)
            insert(element, leaf->left);
        else{
            leaf->left = new node;
            leaf->left->element = element;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if(element > leaf->element){
        if(leaf->right != NULL)
            insert(element, leaf->right);
        else{
            leaf->right = new node;
            leaf->right->element = element;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}
void BSTree::insert(int element){
    if(root != NULL)
        insert(element, root);
    else{
        root = new node;
        root->element = element;
        root->left = NULL;
        root->right = NULL;
    }
}
void BSTree::inorder_print(){
    inorder_print(root);
    printf("\n");
}
void BSTree::inorder_print(node* leaf){
    queue<node*> aux;
    aux.push(leaf);
    while(!(aux.empty())){
        node* u = aux.front();
        aux.pop();
        if(u->left != NULL)
            aux.push(u->left);
        if(u->right != NULL)
            aux.push(u->right);
        printf("%d%s", u->element, (!(aux.empty()))? " " : "");
    }
}

int main(){
    int c, z = 0;
    scanf("%d", &c);
    while(c--){
        z++;
        BSTree* tree = new BSTree();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            tree->insert(aux);
        }
        printf("Case %d:\n", z);
        tree->inorder_print();
        printf("\n");
        delete tree;
    }
    return 0;
}