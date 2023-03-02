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
struct node *AlternateElements(struct node *head1, struct node *head2,struct node *head3){
    struct node *p=head1;
    struct node *q=head2;
    struct node *r=head3;
    struct node *t=head3;
    while(p!=NULL && q!=NULL){
        struct node *ptr=(struct node *) malloc(sizeof(struct node));
        r->data=p->data;
        r=r->next;
        r->data=q->data;
        p=p->next;
        q=q->next;
    }
    while(p!=NULL){
        struct node *ptr=(struct node *) malloc(sizeof(struct node));
        r->data=p->data;
        r=r->next;
        p=p->next;
    }
    while(q!=NULL){
        struct node *ptr=(struct node *) malloc(sizeof(struct node));
        r->data=q->data;
        r=r->next;
        q=q->next;
    }
    return t;
}
int main() {
    struct node *head1 = (struct node *) malloc(sizeof(struct node));
    struct node *head2 = (struct node *) malloc(sizeof(struct node));
    struct node *head3 = (struct node *) malloc(sizeof(struct node));
    struct node *first3 = (struct node *) malloc(sizeof(struct node));
    struct node *first1 = (struct node *) malloc(sizeof(struct node));
    struct node *first2 = (struct node *) malloc(sizeof(struct node));
    struct node *second1 = (struct node *) malloc(sizeof(struct node));
    struct node *second2 = (struct node *) malloc(sizeof(struct node));
    struct node *second3 = (struct node *) malloc(sizeof(struct node));
    struct node *third1 = (struct node *) malloc(sizeof(struct node));
    struct node *third2 = (struct node *) malloc(sizeof(struct node));
    struct node *third3 = (struct node *) malloc(sizeof(struct node));
    struct node *fourth3 = (struct node *) malloc(sizeof(struct node));
    struct node *fifth3 = (struct node *) malloc(sizeof(struct node));
    head3->next=first3;
    first3->next=second3;
    second3->next=third3;
    third3->next=fourth3;
    fourth3->next=fifth3;
    fifth3->next=NULL;

    head1->data = 7;
    head1->next = first1;

    first1->data = 8;
    first1->next = second1;

    second1->data = 9;
    second1->next = NULL;

    head2->data = 2;
    head2->next = first2;

    first2->data = 3;
    first2->next = second2;

    second2->data = 4;
    second2->next = NULL;

    AlternateElements(head1, head2, head3);

    traversal(head3);
}