//
// Created by Shishir Garg on 22/09/22.
//
#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
};
void traversal(struct node *head){
    struct node *p=head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
struct node *concatenate(struct node *head1, struct node *head2){
    struct node *p=head1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=head2;
    return head1;
}
int main(){
    struct node *head1=(struct node *) malloc(sizeof(struct node));
    struct node *head2=(struct node *) malloc(sizeof(struct node));
    struct node *first1=(struct node *) malloc(sizeof(struct node));
    struct node *first2=(struct node *) malloc(sizeof(struct node));
    struct node *second1=(struct node *) malloc(sizeof(struct node));
    struct node *second2=(struct node *) malloc(sizeof(struct node));
    struct node *third1=(struct node *) malloc(sizeof(struct node));
    struct node *third2=(struct node *) malloc(sizeof(struct node));

    head1->data=7;
    head1->next=first1;

    first1->data=8;
    first1->next=second1;

    second1->data=9;
    second1->next=NULL;


    head2->data=2;
    head2->next=first2;

    first2->data=3;
    first2->next=second2;

    second2->data=4;
    second2->next=NULL;

    head1= concatenate(head1,head2);

    traversal(head1);

}
