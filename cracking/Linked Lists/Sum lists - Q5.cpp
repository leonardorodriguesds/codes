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

pair<int, LinkedList*> sumHelper(Node*, Node*);
Node* sumOver(Node*, int, Node*, int);
Node* sum(Node*, Node*, int, Node*);
Node* solveIt(Node*, Node*);

/** Metódo para somar duas linked lists em ordem invertida;
 */
Node* solveIt(Node* lhs, Node* rhs){
    Node* ans = NULL;
    vi sum;
    int carry = 0;
    while(lhs != NULL or rhs != NULL){
        int lhe = lhs != NULL? lhs->e : 0; 
        int rhe = rhs != NULL? rhs->e : 0;
        int sum = (lhe + rhe + carry);
        carry = (sum / 10);
        if(ans == NULL)
            ans = new Node((sum) % 10);
        else
            ans->inserttotail((sum) % 10);
        if(lhs != NULL)
            lhs = lhs->next;
        if(rhs != NULL)
            rhs = rhs->next;
    }
    if(carry != 0)
        ans->inserttotail(carry);
    return ans;
}

Node* sum(Node* lhs, Node* rhs, int carry, Node* ans){
    if(lhs == NULL and rhs == NULL){
        if(carry)
            ans->inserttotail(carry);
        return ans;
    }
    int lhe = lhs != NULL? lhs->e : 0; 
    int rhe = rhs != NULL? rhs->e : 0;
    int result = (lhe + rhe + carry);
    if(ans == NULL)
        ans = new Node((result) % 10);
    else
        ans->inserttotail((result) % 10);
    ans = sum(lhs != NULL? lhs->next : NULL, rhs != NULL? rhs->next : NULL, (result / 10), ans);
    return ans;
}

/** Metódo para somar 2 linked lists em ordem normal de dígitos; 
 */
Node* sumOver(Node* lhs, int n, Node* rhs, int z){
    if(n > z) swap(lhs, rhs); else swap(n, z);
    LinkedList* aux = new LinkedList(lhs);
    for (int i = 0; i < (n - z); i++)
        aux->inserttohead(0);
    lhs = aux->root;
    aux->root = NULL;
    delete aux;
    pair<int, LinkedList*> ans = sumHelper(lhs, rhs);
    if(ans.first != 0)
        ans.second->inserttohead(ans.first);
    Node* response = ans.second->root;
    ans.second->root = NULL;
    delete ans.second;
    return response;
}

pair<int, LinkedList*> sumHelper(Node* lhs, Node* rhs){
    pair<int, LinkedList*> ans;
    if(lhs == NULL and rhs == NULL){
        ans.first = 0;
        ans.second = new LinkedList();
        return ans;
    }
    ans = sumHelper(lhs->next, rhs->next);
    int result = (lhs->e + rhs->e + ans.first);
    ans.second->inserttohead((result) % 10);
    ans.first = (result / 10);
    return ans;
}

int main(){
    int n, z;
    //printf("SIZE LHS: ");
    scanf("%d", &n);
    Node* lhs = NULL;
    Node* rhs = NULL;
    //printf("LEFT HAND SIDE: ");
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        if(lhs == NULL)
            lhs = new Node(aux);
        else
            lhs->inserttotail(aux);
    }
    //printf("SIZE RHS: ");
    scanf("%d", &z);
    //printf("RIGHT HAND SIDE: ");
    for (int i = 0; i < z; i++){
        int aux;
        scanf("%d", &aux);
        if(rhs == NULL)
            rhs = new Node(aux);
        else
            rhs->inserttotail(aux);
    }
    Node* ans = sumOver(lhs, n, rhs, z);
    //Node* ans = solveIt(lhs, rhs);
    ans->printAll();
    delete ans;
    delete lhs;
    delete rhs;
    return 0;
}