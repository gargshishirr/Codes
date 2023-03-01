//
// Created by Shishir Garg on 29/12/22.
//

#include <iostream>
#include<cstring>
using namespace std;

int LCS2mem(string s1,string s2,int **arr){
    int m=s1.size();
    int n=s2.size();
    int ans;
    if(s1.size()==0 || s2.size()==0){
        return 0;
    }
    if(arr[m][n]!=-1){
        return arr[m][n];
    }
    if(s1[0]==s2[0]){
        ans= 1+LCS2mem(s1.substr(1),s2.substr(1),arr);
    }
    else {
        int x = LCS2mem(s1.substr(1), s2,arr);
        int y = LCS2mem(s1, s2.substr(1),arr);
        ans = max(x, y);
    }
    arr[m][n]=ans;
    return ans;
}
int LCS(string s1, string s2){
    int m=s1.size();
    int n=s2.size();
    //int maximum=max(s1.size(),s2.size());
    int **arr=new int *[m+1];
    for(int i=0;i<=m;i++){
        arr[i]=new int  [n+1];
        for(int j=0;j<=n;j++){
            arr[i][j]=-1;
        }
    }
    return LCS2mem(s1,s2,arr);
}
int main(){
    string s1="abcd";
    string s2="abdf";
    cout<<LCS(s1,s2);

return 0;
}