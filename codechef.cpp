#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
    // your code goes here
    unordered_map<int,int> storage;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[j]=x;
        }

        for(int j=0;j<n;j++){
            storage[arr[j]]++;
        }
        int var=-1;
        for(int j=0;j<n;j++){
            if(storage[arr[j]]%2!=0){
                //cout<<"NO"<<endl;
                var=-1;
            }
            else
                var=1;
            //cout<<"YES"<<endl;
        }
        if(var==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;

        }

    }
    return 0;
}
