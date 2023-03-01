#include <iostream>
#include <algorithm>
using namespace std;

void merge(int *array,int l, int m, int r){
    int nl,nr;
    nl=m-l+1;
    nr=r-m;
    int larr[nl];
    int narr[nr];
    for(int i=l;i<=m;i++){
        larr[i-l]=array[i];
    }
    int x=0;
    for(int i=m+1;i<=r;i++){
        narr[x]=array[i];
        x++;
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<nl && j<nr){
        if(larr[i]<narr[j]){
            array[k]=larr[i];
            i++;
            k++;
        }
        else {
            array[k]=narr[j];
            j++;
            k++;
        }
    }
    while(i<nl){
        array[k]=larr[i];
        i++;
        k++;
    }
    while(j<nr){
        array[k]=narr[j];
        j++;
        k++;
    }
}
void mergeSort(int input[], int si, int ei){
    if(si>=ei)
        return;
    int mid=(si+ei)/2;
    mergeSort(input,si,mid);
    mergeSort(input,mid+1,ei);
    merge(input,si,mid,ei);
}
int tripletSum(int *arr, int n, int num)
{
    mergeSort(arr,0,n);
    int count=0;

    for(int i=0;i<n-1;i++){
        int l=i+1;
        int e=n-1;     //0 0 1 2 3 5 5 5 6 6 6
        while(l<e){
            if((arr[i]+arr[l]+arr[e])==num ){
                count++;
                if((arr[i]+arr[l+1]+arr[e])==num && (l+1)!=e)
                    l++;
                else if((arr[i]+arr[l]+arr[e-1])==num && (l+1)!=e)
                    e--;
                else{
                    l++;
                    e--;
                }

            }
            else if((arr[i]+arr[l]+arr[e])<num){
                l++;
            }
            else if((arr[i]+arr[l]+arr[e])>num){
                e--;
            }
        }
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        int x;
        cin >> size;


        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x;

        cout << tripletSum(input, size, x) << endl;

        delete[] input;
    }

    return 0;
}
