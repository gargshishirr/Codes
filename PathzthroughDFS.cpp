/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

//bubble sort iterative
#include <iostream>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *bubbleSort(Node *head)
{
    // Write your code here
    Node *temp=head;
    while(temp!=NULL){
        Node *temp2=temp->next;
        while(temp2!=NULL){
            if(temp->data>temp2->data){
                int data1=temp->data;
                temp->data=temp2->data;
                temp2->data=data1;
                temp2=temp2->next;
            }
        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}