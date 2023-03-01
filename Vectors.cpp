//
// Created by Shishir Garg on 04/12/22.
//
#include<vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> v;
    for(int i=0;i<100;i++){
        cout<<"size:"<<v.size()<<endl;
        cout<<"capacity:"<<v.capacity()<<endl;
        v.push_back(i+1);
    }
    v.push_back(3);
    v.push_back(50);
    v.push_back(100);
    v.push_back(302);
    v.push_back(344);
    v[1]=0;
    // DONT USE [] FOR INSERTING ELEMENTS
    // V[5]=10
    // V[6]=20
    v.push_back(3000);
    v.push_back(4000);
    v.pop_back();
/*
    for(int i=0;i<v.size();v++){
        cout<<v[i]<<endl;
    }
*/
return 0;
}
