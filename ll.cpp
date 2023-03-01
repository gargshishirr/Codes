#include<iostream>
using namespace std;

class B;

class A{
    int a;
public:
    A(){
        a=1;
        cout<<"Bye";
    }
    friend class B;
};

class B{
public:
    int x;

    B(){
        cout<<"hello"<<endl;
        x=a;
    }
};
int main(){
    B obj;
    cout<<obj.x;
    return 0;
}