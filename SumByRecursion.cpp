
#include <iostream>
using namespace std;
int SumByRecursion(int q){
    if(q==0)
        return 0;

    static int sum=0;
    sum=sum+(q%10);
    SumByRecursion(q/10);
    return sum;

}
int main(){
    int n;
    cin>>n;

    cout<<SumByRecursion(n);
    return 0;
}