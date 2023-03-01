//
// Created by Shishir Garg on 13/11/22.
//
#include <iostream>
using namespace std;
class node{
public:
    node *right;
    node *left;
    int data;
    node(int value){
        data=value;
        right=NULL;
        left=NULL;
    }
};
int main(){
    node *root= new node(1);
    root->left=new node(3);
    root->right=new node(4);
    root->left->left=new node(6);
    root->right->right=new node(8);
    return 0;
}