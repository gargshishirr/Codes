
#include<iostream>
using namespace std;
bool isSafe(int grid[9][9],int row, int column,int num){
    for(int i=0;i<9;i++){
        if(grid[row][i]==num)
            return false;
    }
    for(int i=0;i<9;i++){
        if(grid[i][column]==num)
            return false;
    }
    int rowfactor=row-(row%3);
    int columnfactor=column-(column%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+rowfactor][j+columnfactor]==num)
                return false;
        }
    }
    return true;
}
bool gridempty(int grid[9][9],int &row, int &column){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(grid[i][j]==0){
                row=i;
                column=j;
                return true;
            }
        }
    }
    //return false;
}
bool isSudoku(int grid[9][9]){
    int row,column;
    if(!gridempty(grid,row,column))
        return true;
    for(int i=1;i<=9;i++){
        if(isSafe(grid, row,column,i)){
            grid[row][column]=i;
            if(isSudoku(grid)){
                return true;
            }
            grid[row][column]=0;
        }
    }
    return false;
}
int main(){
    int grid[9][9];
    for(int i=0;i<9;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            grid[i][j]=s[j]-'0';


        }
    }
    if(isSudoku(grid)==true){
        cout<<"true";
    }
    else if(isSudoku(grid)==false)
        cout<<"false";



    // write your code here
    return 0;
}
