#include <iostream>
using namespace std;
void merge(int *array, int start, int mid, int end){
    int nl, nr;
    int larr[mid-start+1];
    int rarr[end-mid];
    for(int i=start;i<=mid;i++){
        larr[i-start]=array[i];
    }
    int p=0;
    for(int i=mid+1;i<=end;i++){
        rarr[p]=array[i];
        p++;
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<=(mid-start) && j< (end-mid) ) {
        if (larr[i] < rarr[j]) {
            array[k++] = larr[i++];
        }
        else
            //(larr[i] >= rarr[j])
            array[k++] = rarr[j++];
    }
        while(i<=(mid-start)){
            array[k++]=larr[i++];
        }
        while(i<(end-mid)){
            array[k++]=rarr[j++];
        }
}
void mergesort(int input[],int si, int ei ){
    if(si>=ei)
        return;
    int mid=(si+ei)/2;
    mergesort(input, si,mid);
    mergesort(input, mid+1, ei);
    merge(input, si, mid, ei);
}
int main(){
    int length;
    cin >> length;
    int* input = new int[length];
    for(int i=0; i < length; i++)
        cin >> input[i];

    mergesort(input,0, length);
    for(int i=1; i <=length; i++)
        cout <<input[i];
return 0;
}
