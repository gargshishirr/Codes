//
// Created by Shishir Garg on 05/10/22.
//
#include<iostream>

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int input[], int start, int end){
    int pivot=input[start];
    int count=0;
    for (int i=start;i<end;i++){
        if(input[i]<=pivot)
            count++;
    }
    swap(&input[start],&input[start+count]);
    int i=start;
    int j=end;
    while(i<j){
        while(input[i]<pivot){
            i++;
        }
        while(input[j]>pivot){
            j--;
        }
        if(start<=end){
            swap(&input[i++],&input[j--]);
        }
    }
    return start+count;

}

void quickSort(int input[], int start, int end)
{
    if(start<end)
    {
        int n=partition(input,start,end);

        quickSort(input, start, n-1);

        quickSort(input, n, end);
    }
}
void quickSort(int input[], int size)
{
    quickSort(input, 0, size - 1);
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


