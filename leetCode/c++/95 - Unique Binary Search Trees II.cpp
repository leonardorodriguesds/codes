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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<TreeNode*>> mem;
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        
        mem = vector<vector<TreeNode*>>(n + 1);
        mem[0] = vector<TreeNode*>(1, nullptr);

        for (int i = 1; i <= n; i++) {
            vector<TreeNode*> current;
            for (int j = 1; j <= i; j++) {
                vector<TreeNode*> leftTrees = mem[j - 1];
                vector<TreeNode*> rightTrees = mem[i - j];
                for (TreeNode* left : leftTrees) {
                    for (TreeNode* right : rightTrees) {
                        TreeNode* root = new TreeNode(j);
                        root->left = cloneTree(left);
                        root->right = cloneTree(right, j);
                        current.push_back(root);
                    }
                }
            }
            mem[i] = current;
        }

        return mem[n];
    }

private:
    TreeNode* cloneTree(TreeNode* node, int offset = 0) {
        if (!node) return nullptr;
        TreeNode* newNode = new TreeNode(node->val + offset);
        newNode->left = cloneTree(node->left, offset);
        newNode->right = cloneTree(node->right, offset);
        return newNode;
    }
};


void printTreeNode(TreeNode* node) {
    if (node == nullptr)
        cout << "null, ";
        
    if (node->left != nullptr) {
        printTreeNode(node->left);
    }

    cout << node->val << ", ";

    if (node->right != nullptr) {
        printTreeNode(node->right);
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    auto sol = Solution();
    auto res = sol.generateTrees(3);

    cout << "[";
    for(TreeNode* aux: res) {
        cout << "[";
        printTreeNode(aux);
        cout << "]";
    }
    cout << "]";
    return 0;
}