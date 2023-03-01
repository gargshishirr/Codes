
#include <iostream>
using namespace std;
class queue{
public:
    int front=-1;
    int rear=-1;
    int *arr;
    int size;
    queue (int size){
        this->size=size;
        front=-1;
        rear=-1;
        arr=new int [size];
    }
    void push(int number){
        if(front==0 && rear==size){
            return;
        }
        else if(front==rear==-1){
            front++;
            rear++;
            arr[rear]=number;

        }
        else{
            rear++;
            arr[rear]=number;
        }

    }
    void pop(){
        if(rear==-1 && front==-1){
            return;
        }
        else{
            for(int i=0;i<size-1;i++){
                arr[i]=arr[i+1];
            }
            rear--;
        }

    }
    void frontElement(){
        if(front==-1 && rear==-1){
            return;
        }
        else{
            cout<<arr[0]<<endl;
        }
    }
};

int main(){
    queue q1(6);
    q1.push(3);
    q1.push(5);
    q1.push(7);
    q1.push(2);
    q1.push(9);
    q1.pop();
    q1.frontElement();

return 0;
}