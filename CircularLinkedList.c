//
// Created by Shishir Garg on 15/09/22.
//
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *head){
    struct Node *ptr=head;
    do {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr->next!=head);

}
struct Node *InsertAtFirst(struct Node *head,data){
    struct Node *ptr=(struct Node *)malloc (sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head= ptr;
    return head;
}
int main() {
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = head;

    printf("Before addition\n");
    LinkedListTraversal(head);
    head = InsertAtFirst(head, 20);
    printf("After Addition\n");
    LinkedListTraversal(head);
}
