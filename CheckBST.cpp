//
// Created by Shishir Garg on 25/01/23.
//

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                    new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int checkMin(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MAX;
    }
    int temp=root->data;
    int left= checkMin(root->left);
    int right= checkMin(root->right);
    if(left<temp)
        temp=left;
    if(right<temp)
        temp=right;
    return temp;
}
int checkMax(BinaryTreeNode<int> *root){
    if(root==NULL){
        return INT_MIN;
    }
    int temp=root->data;
    int left= checkMax(root->left);
    int right= checkMax(root->right);
    if(left>temp)
        temp=left;
    if(right>temp)
        temp=right;
    return temp;
}
bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL)
        return true;
    if(root->left!=NULL && checkMax(root->left)>root->data)
        return false;
    if(root->right!=NULL && checkMin(root->right)<root->data)
        return false;
    if(!isBST(root->right) || !isBST(root->left))
        return false;
    return true;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}