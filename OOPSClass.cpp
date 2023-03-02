//
// Created by Shishir Garg on 14/09/22.
//
using namespace std;
#include<iostream>
int main(){
    float c[]={20,40,10,60,30,50};
    float *a[]{c+4,c+1,c+5,c+2,c,c+3};
    float **b=a;
    *++*b;
    cout<<b-a<<" "<<*b-c<<" "<<**b<<endl;
    ++*++b;
    cout<<b-a<<" "<<*b-c<<" "<<**b<<endl;
    ++**b;
    cout<<b-a<<" "<<*b-c<<" "<<**b<<endl;
}

