//
// Created by Shishir Garg on 11/02/22.
//


#include <iostream>
using namespace std;

void swap(int* a, int* b){ //temp a b  // a and b are formal parameters
    int temp = *a;        //4   4  5
    *a = *b;               //4   5  5
    *b = temp;            //4   5  4
}
int main(){
    int x =4, y=5; // x and y are actual parameters
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    swap(x, y);
    cout<<"The value of x is "<<x<<" and the value of y is "<<y<<endl;
    return 0;
}

