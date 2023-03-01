//
// Created by Shishir Garg on 11/11/22.
//

#include <iostream>
using namespace std;
int arr[10];
void heap_insert(int n, int value){
    n=n+1;
    arr[n]=value;
    int i=n;

    while(i>0){
        int parent=i/2;
        if(arr[parent]<arr[i]) {
            swap(arr[parent], arr[i]);

            i=parent; // updation statement
        }
        else
            return;
    }
}
int main(){

    heap_insert(0, 10);
    heap_insert(1,12);
    heap_insert(2,4);
    heap_insert(3,6);
    heap_insert(4,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

return 0;
}