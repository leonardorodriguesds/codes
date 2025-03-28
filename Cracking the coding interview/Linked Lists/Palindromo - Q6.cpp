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

class Node{
    public:
        int e;
        Node* next;
        Node(int element){
            e = element;
            next = NULL;
        };
        ~Node(){
            Node* aux = next;
            delete aux;
        }
        void inserttotail(int element){
            Node* aux = new Node(element);
            Node* in = this;
            while(in->next != NULL)
                in = in->next;
            in->next = aux;
        }
        void inserttotail(Node* aux){
            if(aux == NULL)
                return;
            Node* in = this;
            while(in->next != NULL)
                in = in->next;
            in->next = aux;
        }
        void printAll(){
            Node* aux = this;
            while(aux != NULL){
                cout << aux->e << " ";
                aux = aux->next;
            }
            cout << endl;
        }
};

class LinkedList{
    public:
        Node* root = NULL;
        LinkedList(){
            root = NULL;
        }
        LinkedList(Node* aux){
            root = aux;
        }
        ~LinkedList(){
            if(root != NULL)
                delete root;
        }
        void inserttotail(int e){
            if(root == NULL)
                root = new Node(e);
            else
                root->inserttotail(e);
        }
        void inserttotail(Node* aux){
            if(root == NULL)
                root = aux;
            else
                root->inserttotail(aux);
        }
        void inserttohead(int e){
            Node* aux = new Node(e);
            if(root != NULL)
                aux->inserttotail(root);
            root = aux;
        }
        void inserttohead(Node* aux){
            if(root != NULL)
                aux->inserttotail(root);
            root = aux;
        }
        void printAll(){
            if(root != NULL)
                root->printAll();
        }
};

bool solveIt(Node* root){
    LinkedList* aux = new LinkedList();
    Node* fast = root;
    bool odd = false;
    while(fast != NULL and fast->next != NULL){
        aux->inserttohead(root->e);
        root = root->next;
        fast = fast->next->next;
    }
    if(fast != NULL) root = root->next;
    fast = aux->root;
    while(root != NULL){
        if(fast->e != root->e)
            return false;
        fast = fast->next;
        root = root->next;
    }
    delete aux;
    return true;
}

int main(){
    int n, z;
    //printf("SIZE LHS: ");
    scanf("%d", &n);
    Node* root = NULL;
    //printf("ELEMENTS: ");
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        if(root == NULL)
            root = new Node(aux);
        else
            root->inserttotail(aux);
    }
    Node* aux = root;
    printf("%s\n", solveIt(aux)? "True" : "False");
    delete root;
    return 0;
}