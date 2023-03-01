//
// Created by Shishir Garg on 12/12/22.
//
#include<cmath>
#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
class treeSolution{
private:
    int height(struct Node * node){
        if(node==NULL)
            return 0;
        int left=height(node->left);
        int right=height(node->right);
        int ans=max(left,right)+1;
        return ans;
    }
public:
    int diameter1(Node * node){
        if(node==NULL){
            return NULL;

        }
        int opt1=height(node->left)+height(node->right);
        int opt2= diameter(node->left);
        int opt3= diameter(node->right);
        return max(opt1,max(opt2,opt3));
    }
    int diameter(Node* node){
        if(node==NULL){
            return 0;

        }
        int opt1=diameter(node->right);
        int opt2=diameter(node->left);
        int opt3=height(node->left) + height(node->right)+1;
        int ans=max(opt1, max(opt2,opt3));
        return ans;
    }
    pair <int,int> diameterFast(Node *root){
        if(root==NULL){
            pair<int,int> p=make_pair(0,0);
            return p;
    }
        pair<int,int> left= diameterFast(root->left);
        pair<int,int> right= diameterFast(root->right);
        int opt1=left.first;
        int opt2=right.first;
        int opt3=left.second + right.second +1;
        pair<int,int> ans;
        ans.first=max(opt1, max(opt2,opt3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }

};