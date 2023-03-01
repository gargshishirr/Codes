//
// Created by Shishir Garg on 27/12/22.

#include <iostream>
using namespace std;
int FibonacciUsingDP(int n){
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int nthFibonaccihelper(int n,int *arr){
    if(n<=1){
        return n;

    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int a=nthFibonaccihelper(n-1,arr);
    int b=nthFibonaccihelper(n-2,arr);
    arr[n]=a+b;
    return arr[n];
}
int nthFibonacci(int n){
    int *arr=new int[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=-1;
    }
    return nthFibonaccihelper(n,arr);
}
int main(){
    int n;
    cin>>n;
    cout<<nthFibonacci(n);

return 0;
}