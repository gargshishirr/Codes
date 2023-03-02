#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;

};
void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node)); //Allocating memories for the nodes in the linked list in Heap.
    struct Node *second;
    struct Node *third=(struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node)); //Allocating memories for the nodes in the linked list in Heap..

    //Link first and second node
    head->data=7;
    head->next=second; //THIS POINTS TO THE WHOLE BLOCK OF SECOND THAT IS INCLUDING DATA AND NEXT...

    //Link second and third node
    second->data=10;
    second->next=third;

    //Link third and fourth node
    third->data=35;
    third->next=fourth;

    //terminate the list at the end of fourth node
    fourth->data=100;
    fourth->next=NULL;

    linkedlisttraversal(head);


    return 0;
}
