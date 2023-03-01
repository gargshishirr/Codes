//
// Created by Shishir Garg on 13/11/22.
//
#include <iostream>
using namespace std;
int tree[10];
void TreeInsertRoot(int n){
    if(tree[0]==NULL)
        tree[0]=n;
    else
        return;

}
void insert_left(int n, int parent) {
    if (tree[parent] == NULL) {
        return;
    }
    else {
        tree[(2 * parent)+1] = n;
    }
}
    void insert_right(int n, int parent) {
        if (tree[parent] == NULL) {
            return;
        } else {
            tree[(2 * parent) +2] = n;
        }
    }
    void print_tree() {
        for (int i = 0; i < 10; i++) {
            cout << tree[i] << " ";
        }
    }
    void deletevalue(int n){
        for(int i=0;i<10;i++){
            if(tree[i]==n){
                tree[i]=0;
            }
        }
    }


int main(){
    TreeInsertRoot(10);
    insert_left(5,0);
    insert_right(6, 0);
    insert_left(3, 1);
    insert_right(9, 1);
    insert_right(4, 2);
    deletevalue(5);
    print_tree();

return 0;
}