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
    int e;
    Node* next;

    public:
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
        Node* solveIt(int x){
            Node* less = NULL;
            Node* greater = NULL;
            Node* aux = this;
            Node* next = NULL;
            while(aux != NULL){
                next = aux->next;
                aux->next = NULL;
                if(aux->e < x){
                    if(less == NULL)
                        less = aux;
                    else
                        less->inserttotail(aux);
                } else {
                    if(greater == NULL)
                        greater = aux;
                    else
                        greater->inserttotail(aux);
                }
                aux = next;
            }
            if(less != NULL)
                less->inserttotail(greater);
            else
                less = greater;
            return less;
        }
};

int main(){
    int n;
    scanf("%d", &n);
    Node* list = NULL;
    while(n--){
        int aux;
        scanf("%d", &aux);
        if(list == NULL)
            list = new Node(aux);
        else
            list->inserttotail(aux);
    }
    list->printAll();
    int aux;
    printf("PIVOT NUMBER: ");
    scanf("%d", &aux);
    list = list->solveIt(aux);
    list->printAll();
    delete list;
    return 0;
}