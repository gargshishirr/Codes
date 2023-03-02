#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
//CASE 1 DELETIing THE FIRST ELEMENT OF THE LINKED LIST...
struct Node *DeletionAtBeginning(struct Node *head){
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
//CASE 2 DELETION ELEMENT AT A GIVEN INDEX OF THE LINKED LIST...
struct Node *DeletionAtaGivenIndex(struct Node *head,int num){
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    for (int i=0;i<num-1;i++){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=ptr2->next;
    free(ptr2);
    return head;
}
//CASE 3 DELETIING THE LAST NODE...
struct Node *DeleteTheLastNode(struct Node *head){
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1->next=NULL;
    free (ptr2);
    return head;
}
// CASE 4 DELETING THE ELEMENT WITH A GIVEN VALUE FROM THE LINKED LIST...
struct Node *deletingGivenValue(struct Node *head,int value){
    struct Node *ptr1=head;
    struct Node *ptr2=head->next;
    while(ptr2->data!=value && ptr2->next!=NULL){
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    if(ptr2->data=value) {
        ptr1->next = ptr2->next;
    }
    free(ptr2);
    return head;
}
// CASE 5 DELETING DUPLICATE ELEMENTS FROM THE LINKED LIST...
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *second=(struct Node *)malloc(sizeof(struct Node));
    struct Node *third=(struct Node *)malloc (sizeof(struct Node));
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=11;
    head->next=second;

    second->data=12;
    second->next=third;

    third->data=13;
    third->next=fourth;

    fourth->data=14;
    fourth->next=NULL;
    printf("Before Deletion\n");
    LinkedListTraversal(head);

    head=DeleteTheLastNode(head);
    printf("After Deletion\n");
    LinkedListTraversal(head);

}

