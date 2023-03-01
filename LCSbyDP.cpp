//
// Created by Shishir Garg on 31/12/22.
//
//
// Created by Shishir Garg on 29/12/22.
//

#include <iostream>
#include<cstring>
using namespace std;

int LCS2DP(string s1,string s2){
    int m=s1.size();
    int n=s2.size();
   int ** output=new int *[m+1];
   for(int i=0;i<=m;i++){
       output[i]=new int [n+1];
   }
    //fill first row
    for(int i=0;i<=n;i++){
        output[0][i]=0;
    }
    //fill first column
    for(int j=0;j<=m;j++){
        output[j][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                output[i][j]=1+output[i-1][j-1];
            }
            else{
                int a =output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                int ans=max(a,max(b,c));
                output[i][j]=ans;
            }
        }
    }
    return output[m][n];

}
/*
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
    return LCS2DP(s1,s2,arr);
}
 */
int main(){
    string s1="abcderjf";
    string s2="abdfrjhjkf";
    cout<<LCS2DP(s1,s2);

    return 0;
}