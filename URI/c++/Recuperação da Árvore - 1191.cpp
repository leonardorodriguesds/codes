#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

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
    string prefix, infix;
    while (cin >> prefix >> infix) {
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
