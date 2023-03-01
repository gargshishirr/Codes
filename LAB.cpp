//
// Created by Shishir Garg on 17/01/23.
//

#include <iostream>
#include<queue>
#include<string>
//#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<vector<pair<int,string>>,vector<pair<int,string>>,greater<pair<int,string>>> q;
    q.push(100,"laundry");
    q.push(299,"ironing");
    q.push(499,"badminton");
    q.push(1,"gym");
    while(!q.empty()){
        cout<<q.front()->second;
    }


    return 0;
}