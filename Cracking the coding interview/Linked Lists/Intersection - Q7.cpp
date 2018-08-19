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

pair<Node*, ii> solveIt(LinkedList* lhs, LinkedList* rhs){
    pair<Node*, ii> ans;
    ans.first = NULL;
    ans.second.first = -1;
    ans.second.second = -1;
    if(lhs == NULL or rhs == NULL)
        return ans;
    int a = 0, b = 0;
    Node* first = lhs->root;
    while(first != NULL and first->next != NULL){
        a += 2;
        first = first->next->next;
    }
    if(first != NULL) a++;
    Node* second = rhs->root;
    while(second != NULL and second->next != NULL){
        b += 2;
        second = second->next->next;
    }
    if(second != NULL) b++;
    if(a > b){
        swap(a, b);
        swap(lhs, rhs);
    }
    first = lhs->root;
    second = rhs->root;
    for(int i = 0; i < (b - a); i++)
        second = second->next;
    int intersection = 0;
    while(first != NULL and second != NULL){
        if(first == second){
            ans.first = first;
            ans.second.first = intersection;
            ans.second.second = intersection + (b - a);
            break;
        }
        intersection++;
        first = first->next;
        second = second->next;
    }
    return ans;
}

int main(){
    int n, z, y;
    scanf("%d %d %d", &n, &z, &y);
    LinkedList* lhs = new LinkedList();
    LinkedList* rhs = new LinkedList();
    Node* tail = NULL;
    for (int i = 0; i < n; i++){
        int aux;
        scanf("%d", &aux);
        lhs->inserttotail(aux);
    }
    for (int i = 0; i < z; i++){
        int aux;
        scanf("%d", &aux);
        rhs->inserttotail(aux);
    }
    for (int i = 0; i < y; i++){
        int aux;
        scanf("%d", &aux);
        if(tail == NULL)
            tail = new Node(aux);
        else
            tail->inserttotail(aux);
    }
    lhs->inserttotail(tail);
    rhs->inserttotail(tail);
    lhs->printAll();
    rhs->printAll();
    pair<Node*, ii> ans = solveIt(lhs, rhs);
    printf("%d => [%d, %d]", ans.first != NULL? ans.first->e : -1, ans.second.first, ans.second.second);
    delete lhs;
    delete rhs;
    return 0;
}