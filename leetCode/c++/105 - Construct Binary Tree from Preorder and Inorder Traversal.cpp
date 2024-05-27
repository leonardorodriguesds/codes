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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /* cout << "preorder: ";
        for (auto x: preorder)
            cout << x << ", ";
        cout << endl;
        cout << "inorder: ";
        for (auto x: inorder)
            cout << x << ", ";
        cout << endl; */
        
        auto node = preorder.front();
        preorder.erase(preorder.begin());
        auto node_idx = find(all(inorder), node) - inorder.begin();
        auto left_size = node_idx;
        auto right_size = inorder.size() - 1 - left_size;

        TreeNode* tree_node = new TreeNode{node};
        if (left_size > 0){            
            /* cout << "left: " << left_size << endl; */
            auto inorder_left = vi(left_size);
            auto n = 0;
            for(int i = 0; i < left_size; i++)
                inorder_left[n++] = inorder[i];
            tree_node->left = buildTree(preorder, inorder_left);
        }

        if (right_size > 0){
            /* cout << "right: " << right_size << endl; */
            auto inorder_right = vi(right_size);
            auto n = 0;
            for(int i = node_idx + 1; i < inorder.size(); i++)
                inorder_right[n++] = inorder[i];
            tree_node->right = buildTree(preorder, inorder_right);
        }

        return tree_node;
    }
};

void print_tree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null, ";
        return;
    }
    cout << root->val << ", ";
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
    ios_base::sync_with_stdio(false); 
    vi preorder = vi{3, 9, 20, 15, 7};
    vi inorder = vi{9, 3, 15, 20, 7};
    auto res = Solution().buildTree(preorder, inorder);
    print_tree(res);
    return 0;
}