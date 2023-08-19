#include <bits/stdc++.h>
#define DEBUG false
#define debugf if (DEBUG) printf
#define MAXN 200309
#define MAXM 900009
#define ALFA            256
#define MOD             1000000007
#define INF             0x3f3f3f3f
#define INFLL           0x3f3f3f3f3f3f3f3f
#define EPS             (1e-9)
#define PI              3.141592653589793238462643383279502884
#define all(a)          a.begin(), a.end()
#define fill(t,v)       memset(t, v, sizeof(t))
#define sz(a)           ((int)(a.size()))
#define LOG2(X)         ((unsigned) (8*sizeof(unsigned long long) - __builtin_clzll((X)) - 1))
#define ispow2(v)       ((int(v) & (int(v) - 1)) == 0)
#define scanf2(a, b)    (scanf("%d %d", &a, &b))
#define scanf3(a, b, c) (scanf("%d %d %d", &a, &b, &c))
#define FOR(x,n) for(int x = 0; (x)<int(n); (x)++)
#define FOR1(x,n) for(int x = 1; (x)<=int(n); (x)++)
#define REP(x,n) for(int x = int(n)-1; (x)>=0; (x)--)
#define REP1(x,n) for(int x = int(n); (x)>0; (x)--)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define mset(x, y) memset(&x, (y), sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pair<int, ii>> vpii;
typedef vector<string> vs;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
typedef vector<pqi> vpqi;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(const string& prefix, const string& infix, int& preIndex, int inStart, int inEnd, unordered_map<char, int>& inIndex) {
    if (inStart > inEnd) {
        return nullptr;
    }

    char currentRoot = prefix[preIndex];
    ++preIndex;

    Node* root = new Node(currentRoot);

    if (inStart == inEnd) {
        return root;
    }

    int inIndexVal = inIndex[currentRoot];

    root->left = buildTree(prefix, infix, preIndex, inStart, inIndexVal - 1, inIndex);
    root->right = buildTree(prefix, infix, preIndex, inIndexVal + 1, inEnd, inIndex);

    return root;
}

void printPostorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        string prefix, infix;
        cin >> c >> prefix >> infix;
        unordered_map<char, int> inIndex;
        for (int i = 0; i < infix.size(); ++i) {
            inIndex[infix[i]] = i;
        }

        int preIndex = 0;
        Node* root = buildTree(prefix, infix, preIndex, 0, infix.size() - 1, inIndex);

        printPostorder(root);
        cout << endl;
    }
    return 0;
}