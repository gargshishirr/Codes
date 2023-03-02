//
// Created by Shishir Garg on 15/09/22.
//
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void listtraversal(struct Node *ptr){
    while(ptr !=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
//CASE 1
struct Node *InsertionAtBeginning(struct Node *head,int data){
    struct Node *ptr=(struct Node *) malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//CASE 2
struct Node *InsertionInBetween(struct Node *head,int data,int index){
    struct Node *ptr=(struct Node *) malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i<index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
// CASE 3
struct node *InsertionAtLast(struct Node *head,int data){
    struct Node *ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    while(p->next != NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;

}

//CASE 4
struct Node *InsertAfterANode(struct Node *head,struct Node *previousNode,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=previousNode->next;
    previousNode->next=ptr;
    ptr->data=data;
    return head;

}
int main(){
    struct Node *head= (struct Node*) malloc(sizeof(struct Node));
    struct Node *second= (struct Node*) malloc(sizeof(struct Node));
    struct Node *third= (struct Node*) malloc(sizeof(struct Node));
    struct Node *fourth= (struct Node*) malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;
    second->data=37;
    second->next=third;
    third->data=19303;
    third->next=fourth;
    fourth->data=90;
    fourth->next=NULL;

    head=InsertAfterANode(head, second,45);
    listtraversal(head);
}
