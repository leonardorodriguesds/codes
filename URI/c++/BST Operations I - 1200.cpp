#include <bits/stdc++.h>
using namespace std;
#define INF             (1e9 + 7)
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<string> vs;

typedef struct s_node{
    char element;
    struct s_node* left;
    struct s_node* right;
} node;

class BSTree{
    private:
        node* root;
        void destroy_tree(node *leaf);
        void insert(char element, node *leaf);
        node *search(char element, node *leaf);
        void inorder_print(node *leaf);
        void postorder_print(node *leaf);
        void preorder_print(node *leaf);
    public:
        BSTree();
        ~BSTree();
        void insert(char element);
        bool exists(char element);
        node *search(char element);
        void destroy_tree();
        void inorder_print();
        void postorder_print();
        void preorder_print();
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
void BSTree::insert(char element, node *leaf){
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
void BSTree::insert(char element){
    if(root != NULL)
        insert(element, root);
    else{
        root = new node;
        root->element = element;
        root->left = NULL;
        root->right = NULL;
    }
}
node* BSTree::search(char element){
    if(root != NULL)
        return search(element, root);
    return NULL;
}
node* BSTree::search(char element, node* leaf){
    if(leaf != NULL){
        if(element == leaf->element)
            return leaf;
        if(element < leaf->element)
            return search(element, leaf->left);
        else
            return search(element, leaf->right);
        return search(element, root);
    }
    return NULL;
}
bool BSTree::exists(char element){
    return (search(element) != NULL);
}
void BSTree::inorder_print(){
    inorder_print(root);
    printf("\n");
}
void BSTree::inorder_print(node* leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        printf("%c ", leaf->element);
        inorder_print(leaf->right);
    }
}
void BSTree::postorder_print(){
    postorder_print(root);
    printf("\n");
}
void BSTree::postorder_print(node* leaf){
    if(leaf != NULL){
        inorder_print(leaf->left);
        inorder_print(leaf->right);
        printf("%c ", leaf->element);
    }
}
void BSTree::preorder_print(){
    preorder_print(root);
    printf("\n");
}
void BSTree::preorder_print(node* leaf){
    if(leaf != NULL){
        printf("%c ", leaf->element);
        inorder_print(leaf->left);
        inorder_print(leaf->right);
    }
}

int main(){
    BSTree *aux = new BSTree();
    char command[30];
    while(scanf("%[^\n]c", command)){
        if(strcmp(command, "INFIXA") == 0)
            aux->inorder_print();
        else if(strcmp(command, "PREFIXA") == 0)
            aux->preorder_print();
        else if(strcmp(command, "POSFIXA") == 0)
            aux->postorder_print();
        else{
            char cmd;
            char element;
            sscanf(command, "%c %c", &cmd, &element);
            switch(cmd){
                case 'I':
                    aux->insert(element);
                    break;
                case 'P':
                    printf("%c %s\n", element, ((aux->exists(element))? "existe": "nao existe"));
            }
        }
        getchar();
    }
    delete aux;
    return 0;
}