//
// Created by Shishir Garg on 08/12/22.
//
#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                    new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int> *buildTreeHelper(int *preorder, int preStart, int preEnd,
                                     int *inorder, int inStart, int inEnd) {
    if (preStart > preEnd)
        return NULL;

    int rootdata = preorder[preStart];
    int rootindex = -1;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootdata) {
            rootindex = i;
            break;
        }
    }
    int LinS = inStart;
    int LinE = rootindex - 1;
    int LpreS = preStart + 1;
    int LpreE = LpreS + LinE - LinS;
    int RpreS = LpreE + 1;
    int RpreE = preEnd;
    int RinS = rootindex + 1;
    int RinE = inEnd;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = buildTreeHelper(preorder, LpreS, LpreE, inorder, LinS, LinE);
    root->right = buildTreeHelper(preorder, RpreS, RpreE, inorder, RinS, RinE);
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return buildTreeHelper(preorder, 0, preLength-1, inorder,0, inLength-1);


}
int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
