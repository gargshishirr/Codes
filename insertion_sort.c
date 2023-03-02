#include <stdio.h>

int main(){
    int arr[100];
    int n,temp,key,j;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;++i){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;  //actully j is already decresed so hence it pointing at the 0th element here
    }
    for(int i=0;i<n;++i) {
        printf("%d", arr[i]);
    }
}
