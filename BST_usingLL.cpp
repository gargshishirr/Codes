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
        left=NULL;
        right=NULL;
    }

};
node* insert(node *root,int value){
    if(root==NULL){
        return new node(value);
    }
    else{
        node *temp;
        if(value<=root->data){

            root->left=insert(root->left,value);;
        }
        else
        {
            root->right=insert(root->right,value);
        }
        return root;
    }
}
void inorder(node* root){
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
void postorder(node *root){
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
void preorder(node *root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}
void search(node* &root, int key){
    node *temp=root;
    while(temp!=NULL && temp->data!=key){
        if(temp->data==key) {
            cout << "found";
            break;
            return;
        }
        else if(temp->data<key)
            temp=temp->right;
        else if(temp->data>key)
            temp=temp->left;
    }
    cout<<" Not found";
    return;

}
node *MinVal(node *root){
    while(root!=NULL){
        root=root->left;

    }
    return root;
}
node* deletenode(node *root, int key){
    if(root==NULL)
        return root;
    if(key<root->data){
        root->left= deletenode(root->left,key);
    }
    else if(key>root->data)
        root->right= deletenode(root->right,key);
    else{
        if(root->right==NULL && root->left==NULL){
            return NULL;
        }
        else if(root->right==NULL ){
            node *temp=(root->left);
            free(root);
            return temp;

        }
        else if(root->left==NULL){
            node *temp=root->right;
            free(root);
            return temp;
        }
        else{ //REPLACE IT WITH THE INORDER SUCCESSOR...
            node *temp= MinVal(root->right);
            root->data=temp->data;
            root->right= deletenode(root->right, temp->data);
        }
        return root;
    }
}

int main(){
    //node tree(0);
    node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root, 4);
    root=insert(root, 35);
    root=insert(root, 6);
    inorder(root);
    cout<<endl;
    deletenode(root,20);
    inorder(root);
    search(root,4);

return 0;
}