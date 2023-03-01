//
// Created by Shishir Garg on 15/12/22.
//
#include<unordered_map>
#include <iostream>
#include<vector>
using namespace std;
vector<int> removeDuplicates(int *a,int size){
    vector<int>output;
    unordered_map<int,bool> seen;
    for(int i=0;i<size;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        else{
            seen[a[i]]=true;
            output.push_back(a[i]);
        }
    }
    return output;
}
int main(){
    int a[]={1,2,3,4,2,3,5,1,6,7,3};
    vector<int> output= removeDuplicates(a,11);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }


return 0;
}
