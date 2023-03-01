//
// Created by Shishir Garg on 02/11/22.
//
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
    // Define the data members
    Node *head;
    int size;
public:

    Stack() {
        head=NULL;
        size=0;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        Node* newnode;
        newnode = new Node(element);
        newnode->data = element;
        if (head == NULL) {
            newnode->next=NULL;
            head=newnode;
            size++;
        }
        else{

            newnode->next = head;
            head = newnode;
            size++;
        }
    }

    int pop() {
        if (head != NULL) {
            int temp = head->data;
            head=head->next;
            size--;
            return head->data;
        }

        // Implement the pop() function
    }

    int top() {
        return head->data;
        // Implement the top() function
    }
};
int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}