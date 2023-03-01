//
// Created by Shishir Garg on 04/10/22.
//
#include <iostream>
using namespace std;
bool BinarySearch(int *arr, int start,int end, int key){
    if(start>end)
        return false;
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
        return true;

    if(key>arr[mid])
        return BinarySearch(arr,mid+1, end, key);
    else if(key<arr[mid])
    {
        return BinarySearch(arr, start, mid - 1, key);
    }
}


int main(){
    int arr[10]={1,4,6,2,3, 7, 8, 5 ,9, 16};
    int size=10;
    int key=10 ;

    cout<<BinarySearch(arr, 0, size-1, key);
    return 0;
}