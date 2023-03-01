//
// Created by Shishir Garg on 05/12/22.
//
#include<vector>
#include<queue>
#include <iostream>
using namespace std;
template< typename T>
class treenode{
public:
    T data;
    vector<treenode*>children;
    treenode(int data){
        this->data=data;
    }
    ~ treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
treenode<int>* takeinputlevelwise(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    queue <treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        treenode<int>* front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter number of children of:"<<front->data;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout<<"Enter "<<i<<"th child data"<<endl;
            cin>>childdata;
            treenode<int>* child=new treenode<int> (childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;

}
treenode<int>* takeinput(){
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;
    treenode<int>* root=new treenode<int>(rootdata);
    int n;
    cout<<"enter number of children of:"<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>* child=takeinput();
        root->children.push_back(child);

    }
    return root;
}
void printtree(treenode<int>* root){
    if(root==NULL)
        return;
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printtree(root->children[i]);
    }
}
void printatlevelK(treenode<int>* root, int k){
    if(root==NULL)
        return;
    if(k==0) {
        cout << root->data;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printatlevelK(root->children[i],k-1);
    }
}
int main(){
    treenode<int>* root=takeinputlevelwise();
    printtree(root);
    return 0;
}
