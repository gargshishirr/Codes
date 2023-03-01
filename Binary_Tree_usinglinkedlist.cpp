//
// Created by Shishir Garg on 08/11/22
#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *next;

};
struct binary_tree{
    int data;
    struct binary_tree *left, *right;

};
void insertatbeginning(struct node **head, int data){
    struct node *new_node=new node;
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}
int main(){
return 0;
}