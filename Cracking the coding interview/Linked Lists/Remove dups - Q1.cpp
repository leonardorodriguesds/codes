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
        void printAll(){
            Node* aux = this;
            while(aux != NULL){
                cout << aux->e << " ";
                aux = aux->next;
            }
            cout << endl;
        }
        void remodedup(){
            map<int, bool> controll;
            Node* aux = this;
            controll[e] = true;
            while(aux->next != NULL){
                if(controll[aux->next->e] == true){
                    Node* del = aux->next;
                    aux->next = aux->next->next;
                    del->next = NULL;
                    delete del;
                } else{
                    controll[aux->next->e] = true;
                    aux = aux->next;
                }
            }
        }
        void removetwodup(){
            Node* aux = this;
            while(aux != NULL){
                Node* two = aux;
                while(two != NULL and two->next != NULL){
                    if(aux->e == two->next->e){
                        Node* del = two->next;
                        two->next = two->next->next;
                        del->next = NULL;
                        delete del;
                    }
                    two = two->next;
                }
                aux = aux->next;
            }
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
    printf("SELECT REMOVE TYPE: ");
    scanf("%d", &aux);
    if(!aux)
        list->remodedup();
    else
        list->removetwodup();
    list->printAll();
    delete list;
    return 0;
}